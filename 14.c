#include <stdio.h>
#include <stdint.h>


static uint32_t collatz(uint32_t n)
{
    uint32_t len = 1;
    while (n != 1) {
        //printf(" %i ->", n);
        if (n & 1) {
            n = 3*n + 1;
        } else {
            n = n/2;
        }
        len++; 
    }
    //puts(" 1");
    return len;
}

uint32_t best = 0;
uint32_t best_len = 0;

uint32_t main() 
{
    uint32_t len;
    for (uint32_t i = 1; i < 1000000; i++) {
        len = collatz(i);
        if (len > best_len) {
            best = i;
            best_len = len;
        }
        printf("length: %i | starting: %i\n", len, i);
        printf("best length: %i | starting: %i\n", best_len, best);
    }

    return 0;
}