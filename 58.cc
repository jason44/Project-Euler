#include <iostream>
#include <cassert>
#include "utils.h"
using namespace std;

int primes = 0;
int samples = 1;
int main()
{
    int dim = 1;
    int cur = 1;
    float ratio = 1;
    for (int i = 1; ratio > 0.1; i++) {
        for (int j = 0; j < 4; j++) {
            if (is_prime(cur)) {
                primes++;
            }
            samples++;
            cur = cur + 2*i;
        }

        dim += 2;
        ratio = (float)primes / samples;

        cout << primes << '/' << samples << " = " << ratio << '\n';
        cout << dim << '\n' << '\n';
    }

    cout << "FINAL: " << primes << '/' << samples << " = " << ratio << '\n';
    cout << "FINAL DIM: " << dim << endl;

    return 0;
}