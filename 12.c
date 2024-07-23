#include <stdio.h>
#include <stdint.h>
#include <math.h>


/* Theorem 1:
 * if n is odd, then its divisors are all odd
 * Theorem 2:
 * if n is odd, then its greatest divisor that is not n itself is less than floor(n/2)
 * Lemma 1: 
 * if n is even then a finite amount k of 2s can be factored out such that n/2k is odd 
 * Theorem 3:
 * The number of divisors of n is equal to k times the number of divisors of n/2k, where k is the integer such that n/2k is odd
 */
//#define TEST

static inline uint32_t triangle(uint32_t t)
{
    uint32_t ret = 0;
    for (int i = 1; i < t + 1; i++) ret += i;
    return ret;
}

int main() 
{
    uint32_t t = 2;
    uint32_t best_tri = 0;
    uint32_t best_t = 0;
    uint32_t best_div = 0;

    while (1) {
        uint32_t tri = triangle(t);
        uint32_t f_tri = tri;
        uint32_t num_div = 0;
        int j = 1;
        if (tri & 1) {
            // for 1 and tri itself. This means that this algorithm is wrong for t=1
            num_div += 2;

            for (int i = 3; i < f_tri / 2; i += 2) {
                if (f_tri % i == 0) {
                    num_div += 1;
                }
            }
        } else {
            uint32_t twos = 0;
            while (!(f_tri & 1)) {
                f_tri /= 2;
                twos++;
            }
            // for f_tri itself
            num_div += 1 + twos;

            for (int i = 1; i < (f_tri / 2) + 1; i += 2) {
                if (f_tri % i == 0) {
                    num_div += 1 + twos;
                }
            }
        }

#ifdef TEST
        if (t > 12) {
            return 0;
        }
#endif
        if (num_div > best_div) {
            best_tri = tri; 
            best_t = t;
            best_div = num_div;
        }
        if (num_div > 500) {
            printf("FINAL: %i | %i | num. divisors: %i\n", tri, t, num_div);
            return 0;
        } else {
            printf("%i | %i | num. divisors: %i\n", tri, t, num_div);
            printf("CURRENT BEST %i | %i | num. divisors: %i\n", best_tri, best_t, best_div);
        }
        t++;
    }
}


// runtime 3:22 min

