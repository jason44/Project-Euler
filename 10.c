#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

const uint32_t TOP = 2000000;
//const uint32_t TOP = 10;

// even numbers can't be prime
// 2 is prime 
// 1 is not prime
static int is_prime(uint32_t x) {
	for (uint32_t i = 1; i < x; i += 2) {
		if (!(x % i) && (i != 1))
			return 0;
	}
	return 1;
}

int main() {
    uint64_t sum = 1; // hard code 2-1
	for (uint32_t i = 1; i < TOP; i+= 2) {
        if (is_prime(i)) {
			sum += i;
			printf("| %u | %lu |\n", i, sum);
        }
    }
}
