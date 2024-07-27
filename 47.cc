#include <iostream>
#include <cmath>
#include <cassert>
#include <vector>
#include <map>
#include <unordered_map>
#include "utils.h"
using namespace std;

unordered_map<int, bool> prime_factors;
vector<int> primes = {2};


int num_prime_factors(int m) 
{
    int n = m;
    int factors = 0;
    for (auto &prime : primes) {
        if (prime > n + 1 || factors > 4) {
            break;
        }
        int q = n / prime;
        int r = n - q*prime;
        if (r == 0) {
            // the prime factor could appear multiple times, 
            // but we only need to consider its first appearance
            n /= prime;
            factors++;
        }
    }
    return factors;
}

int main() 
{
    // exclude 2 from the primes list
    for (int m = 3; m < 100000; m += 2) {
        if (is_prime(m)) {
            primes.push_back(m);
        }
    }

    bool found = false;
    for (int n1 = 644; !found; n1++) {
        int n2 = n1 + 1;
        int n3 = n1 + 2;
        int n4 = n1 + 3;
        cout << n1 << ", " << n2 << ", " << n3 << ", " << n4 << '\n';

        bool mask = true;
        mask &= (num_prime_factors(n1) == 4);
        mask &= (num_prime_factors(n2) == 4);
        mask &= (num_prime_factors(n3) == 4);
        mask &= (num_prime_factors(n4) == 4);

        prime_factors.clear();
        if (mask == true) {
           cout << "FOUND: " << n1 << ", " << n2 << ", " << n3 << ", " << n4 << endl;
           found = true;
        }
    }

}
