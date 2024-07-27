#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include "utils.h"

using namespace std;

int main()
{
    vector<int> primes = {};
    int counter_ex = 0;
    for (int n = 3; counter_ex == 0; n += 2) {
        if (is_prime(n)) {
            primes.push_back(n);
        cout << n << " | PRIME\n";
            continue;
        }

        bool f = false;
        cout << n << '\n';
        for (auto &p : primes) {
            // p = 2 will never be considered as g will be odd in that case
            int g = (n - p) / 2;
            assert((n-p) % 2 == 0);
            if (is_square(g)) {
                f = true;
                cout << n << " = " << p << " + " << "2*" << g << '\n';
            }
        }

        if (f == false) {
            counter_ex = n;
        }
    }
    cout << "FOUND: " << counter_ex << endl;
    return 0;
}