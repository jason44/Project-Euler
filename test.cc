#include <iostream>
#include <vector>
#include <cassert>
#include "utils.h"

using namespace std;
#define ASCII(x) (char)(x+48)

int main()
{
    vector<int> primes = {2};
    for (int n = 3; n < 100000; n += 2) {
        if (is_prime(n)) {
            primes.push_back(n);
            //cout << n << '\n';
        }
    }
    cout << ASCII(9) << '\n';
    assert(ASCII(9) == '9');
    return 0;
}