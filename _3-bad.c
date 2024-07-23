#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <math.h>

#define NTHREADS 12

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static const uint64_t num = 600851475143;
static const uint64_t cand = 8462696833;
static const int step = 1000000;
static const int jump = NTHREADS * step;
static uint64_t candidates[20];
static uint64_t *top = candidates;
static uint64_t iter = 1;

static struct data {
	int id;
};

void* findfactors(void *data);


int main() {
	pthread_t thread_id[NTHREADS]; 
	for (uint64_t j = 0; j < ((uint64_t)sqrt(num) + jump); j += jump) {
		for (int i = 0; i < NTHREADS; i++) {
			pthread_create(&thread_id[i], NULL, findfactors, (void *)i);
		}
		for (int i = 0; i < NTHREADS; i++) {
			pthread_join(thread_id[i], NULL);
		}
		iter += jump;
	}
	// since num is odd, its factors must be odd
	return 0;
}

void* findfactors(void *data) {
	int datav = (int)data + 1;
	//printf("%i\n", datav);
	uint64_t offset = (datav - 1) * step;
	uint64_t stride = datav * step;
	if (iter + offset > num) 
		return NULL;
	//printf("offset: %lu\nstride: %lu\n", offset, stride);
	for (uint64_t i = (iter + offset); i < (iter + stride); i += 2) {
		if (!(num % i)) {
			pthread_mutex_lock(&mutex);
			*top = i;
			top++;
			printf("%lu\n", i);
			pthread_mutex_unlock(&mutex);
		}
	}
	return NULL;
}
