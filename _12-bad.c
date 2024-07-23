#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdalign.h>
#include <stdatomic.h>
#include <pthread.h>
#include <immintrin.h>
//gcc 12.c -march=native -lpthread -o 12

// 379 with built-in mod operator: 2m5.429s
// 379 with mm256_mod_i32: TOO DAMN LONG

#define DEBUG
#ifdef DEBUG
	#define NFACTORS 500
	#define NTHREADS 1
#else 
	#define NFACTORS 500
	#define NTHREADS 8
#endif

#define BLOCKS 8

#define QADDS(x, i) (i >= x) ? (0) : (x - i)
#define STRIDEOF(x) ((x & 1) ? (1) : (1))

alignas(32) const uint32_t _zero_buf[BLOCKS] = {0, 0, 0, 0, 0, 0, 0 , 0};
const __m256i *zero_buf = (__m256i *)_zero_buf;

alignas(32) const uint32_t _one_buf[BLOCKS] = {1, 1, 1, 1, 1, 1, 1, 1};
const __m256i *one_buf = (__m256i *)_one_buf;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
atomic_int nready = 0;
atomic_int ndone = 0;
static int cond = 0;
static uint32_t candidate = 0;

// takes copies so in place is fine
__m256i _mm256_mod_i32(__m256i _A, __m256i _B) {
	uint32_t * _A_rray = (uint32_t *)&_A;
	uint32_t * _B_rray = (uint32_t *)&_B;
	__m256i _subB = _mm256_sub_epi32(_B, *one_buf);
	const uint32_t END = _A_rray[7] / _B_rray[7];
	for (uint32_t i = 0; i < END; i++) {
		__m256i cmp = _mm256_cmpgt_epi32(_A, _subB); // if value at _A is less than _B(mod), return 0
		//_B = (__m256i)_mm256_and_ps((__m256)_B, (__m256)cmp);
		uint32_t *cmp_rray = (uint32_t *)&cmp;
		for (int j = 0; j < BLOCKS; j++) {
			_B_rray[j] &= cmp_rray[j];
		} 
		_A = _mm256_sub_epi32(_A, _B);
	}
	return _A;
}



void get_res(uint32_t *n) {
	__m256i *tn = (__m256i *)n;
	/*printf("tri_nums: %u, %u, %u, %u, %u, %u, %u, %u\n", n[0], n[1], n[2], n[3],
														 n[4], n[5], n[6], n[7]);*/
	// note i = 1 because 'n' already stores the tri_num itself
	alignas(32) uint32_t ncpy[BLOCKS];
	memcpy(ncpy, n, (sizeof(ncpy[0])*BLOCKS));
	for (int i = 1; i < ncpy[7]; i++) {
	 	alignas(32) uint32_t adds[BLOCKS] = {
			QADDS(ncpy[0], i), QADDS(ncpy[1], i), QADDS(ncpy[2], i), QADDS(ncpy[3], i),
			QADDS(ncpy[4], i), QADDS(ncpy[5], i), QADDS(ncpy[6], i), QADDS(ncpy[7], i),
		};
		__m256i *ta = (__m256i *)adds;
		*tn = _mm256_add_epi32(*tn, *ta);
	}
	uint32_t *ret = (uint32_t *)tn;
	/*printf("exp_nums: %u, %u, %u, %u, %u, %u, %u, %u\n", ret[0], ret[1], ret[2], ret[3],
												         ret[4], ret[5], ret[6], ret[7]);*/
}

void count_factors(uint32_t *n) {
	get_res(n);
	#define res n
	__m256i *tr = (__m256i *)res;
	
	alignas(32) uint32_t iterlist[BLOCKS] = {
		0, 0, 0, 0, 0, 0, 0, 0
	};
	__m256i *ti = (__m256i *)iterlist;

	alignas(32) uint32_t factor_buf[BLOCKS] ={
		0, 0, 0, 0, 0, 0, 0, 0
	};
	__m256i *tf = (__m256i *)factor_buf;

	alignas(32) uint32_t strides[BLOCKS] = {
		STRIDEOF(res[0]), STRIDEOF(res[1]), STRIDEOF(res[2]), STRIDEOF(res[3]),
		STRIDEOF(res[4]), STRIDEOF(res[5]), STRIDEOF(res[6]), STRIDEOF(res[7]),
	};
	__m256i *ts = (__m256i *)strides;	

	__m256i add;
	for (uint32_t i = 1; i < res[7]; i += STRIDEOF(res[7])) {
		*ti = _mm256_add_epi32(*ti, *ts); // add strides to get new factor candidate
		uint32_t mods[BLOCKS];
		for (int j = 0; j < BLOCKS; j++) {
			mods[j] = res[j] % iterlist[j];
		}
		__m256i *tm = (__m256i *)mods;
		//__m256i tm = _mm256_mod_i32(*tr, *ti); // see if factor candidates are actual factors of the value 
		//uint32_t *_mod = (uint32_t *)&tm; 
		//printf("(mod %i): %i, %i, %i, %i, %i, %i, %i, %i\n",iterlist[0], _mod[0], _mod[1], _mod[2], _mod[3], 
		//											   	    _mod[4], _mod[5], _mod[6], _mod[7]); 
		
		add = _mm256_cmpeq_epi32(*tm, *zero_buf); // mod[] = 0 ? -1 : 0 
		*tf = _mm256_sub_epi32(*tf, add);	

	}
	for (int j = 0; j < BLOCKS; j++) {
		printf("trinum: %u | expand: %u | factors: %i\n",res[j]-res[j-((j-1)>=0?(1):0)], res[j], factor_buf[j]);
		#if NTHREADS != 1
		pthread_mutex_lock(&lock);
		#endif
		if (factor_buf[j] > cond) {
			cond = factor_buf[j];
			candidate = res[j];
		}
		#if NTHREADS != 1
		pthread_mutex_unlock(&lock);
		#endif
	}
}


void *factors_thread(void *n) {
	
	#if NTHREADS != 1
	nready++;
	pthread_mutex_lock(&lock);
	pthread_mutex_unlock(&lock);
	#endif	

	count_factors((uint32_t *)n);
	
	#if NTHREADS != 1
	ndone++;
	#endif

	return NULL;
}

pthread_t threads[BLOCKS];

int main() {
	//uint64_t res = 0;
	uint32_t tri_num = 5000;
	do {
		alignas(32) uint32_t test_nums[BLOCKS] = {
			tri_num, tri_num+1, tri_num+2, tri_num+3, 
			tri_num+4, tri_num+5, tri_num+6, tri_num+7
		};
		#if NTHREADS != 1
		pthread_mutex_lock(&lock);
		for (int j = 0; j < NTHREADS; j++) {
			pthread_create(&threads[j], NULL, factors_thread, (void *)test_nums);
		} 
		for (int j = 0; j < NTHREADS; j++) {
			pthread_join(threads[j], NULL);
		}
		pthread_mutex_unlock(&lock); 
		#else
		factors_thread((void *)test_nums);
		#endif

		tri_num += BLOCKS*NTHREADS;
		printf("current cond: %i\ncurrent best: %u\n", cond, candidate);

	} while (cond < NFACTORS);
    //printf("%i -> factors: %i\n", tri_num, cond);
}

