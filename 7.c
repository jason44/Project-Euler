#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define NPRIME 10001

static bool is_prime(uint64_t x) {
	for (uint64_t i = 2; i < x; i++) {
		if (!(x % i))
			return false;	
	}
	return true;
}

int main() {
    int iter = 0;
    uint64_t num = 1;
    while (iter < NPRIME) {
        if (is_prime(num)) {
            iter++;
            printf("(%i: %lu)\n", iter, num);
        }
        num += 2;
    }
}
