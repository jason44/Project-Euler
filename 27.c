#include <stdio.h>
#include <math.h>


// if a and b are both even then n=2 is even and thus not prime
// if a is even and b is odd, then n=3 is even
// if a is odd and b is even, then n=2 is even
// if a and b are both odd and not coprime, then there sequence terminates at n=g where g is the smallest divisor of a and b
//    note: g is always prime (otherwise it wouldn't be the smallest)
// if a or b are both odd and coprime, then the sequence terminates at n=g where g is the smallest divisor of b
//    proof: At n=g, we get g^2 + a*g + g*... Clearly, this sum can be divided by g
// 
// it follows that a and b must be prime numbers.
// 

int best_num = 0;
int best_prod = 0;
int prime_numbers[500] = {1, 2};
int idx = 2;

static inline int is_prime(int n)
{
    // algorithm below only holds for n >= 3
    // so we manually define outputs for 1,2,3
    if (n == 0) return 0;
    if (n == 1) return 0;
    if (n == 2) return 1;

    // factor out -1 if it is a factor
    if (n < 0) {
        n *= -1;
    }

    if (n & 1) {
        for (int i = 3; i < n/2; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}

static inline void count(const int a, const int b)
{
    int primes = 0;
    int d;
    int res;
    int k = 0;
    do {
        d = pow(k, 2) + (a*k) + b;
        res = is_prime(d);
        k++;
    } while(res);

    if (k > best_num) {
        best_num = k;
        best_prod = a * b;
    }
    
    printf("a=%i, b=%i, num. primes = %i\n", a, b, k);

}

int main()
{
    for (int i = 3; i < 1000 + 1; i++) {
        if (is_prime(i)) {
            //printf("%i\n", i);
            prime_numbers[idx] = i;
            idx++;
        }
    }

    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < idx; j++) {
            int a = prime_numbers[i];
            int b = prime_numbers[j];
            int neg_a = a * -1;
            int neg_b = b * -1;

            count(a, b);
            count(a, neg_b);
            count(neg_a, neg_b);
            count(neg_a, b);
        }
    }

    printf("BEST: a*b = %i, num. primes = %i\n", best_prod, best_num);


    return 0;
}