#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

static const uint64_t num = 600851475143;

static int is_odd(int x) {
	// if first bit is 1 return true else return false
	return (x & 1);	
}

static int get_stride(uint64_t x) {
	// factors of odd numbers are odd numbers
	return is_even(x) ? 1 : 2;
}

static uint32_t *find_factors(uint64_t x) {
	int stride = get_stride(x);
	printf("%lu\n", (uint64_t)sqrt(x));
	uint32_t *ret = malloc(sizeof(*ret)*20);
	int iter = 0;
	// prime factors of x must be less than sqrt(x)
	for (uint64_t i = 2; i < (uint64_t)sqrt(x); i += stride) {
		if (!(x % i)) {
			ret[iter] = i;
			iter++;
			printf("%lu\n", i);
		}
	}
	return ret;
}

static bool is_prime(uint32_t x) {
	int stride = get_stride(x);
	for (uint32_t i = 2; i < x; i += stride) {
		if (!(x % i))
			return false;	
	}
	return true;
}

int main() {
	uint32_t *candidates = find_factors(num);
	for (int i = 0; i < 20; i++) {
		if (candidates[i] == 0) break;
		bool res = is_prime(candidates[i]);	
		printf("%i is prime?: %i\n", candidates[i], res);
	}
	return 0;
}



