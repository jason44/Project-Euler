#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include "utils.h"

using namespace std;

map<int, int> seen;
int stop = 1000000;
int circular_primes = 1;


int main()
{
    int next_place = 10;
    int current_place = 1;
    for (int n = 3; n < stop; n += 2) {
        if (n > next_place) {
            next_place *= 10;
            current_place *= 10;
        }
        if (seen.find(n) != seen.end()) {
            continue;
        }

        vector<int> digits;
        int q = n / current_place;
        int r = n - (current_place * q);
        int tmp_place = current_place / 10;
        digits.push_back(q);
        while (r != 0) {
            q = r / tmp_place;
            r = r - (tmp_place * q);
            digits.push_back(q);
            tmp_place /= 10;
        }
        reverse(digits.begin(), digits.end());

        int circ_prime = 1;
        set<int> circ_nums;
        for (int offset = 0; offset < digits.size(); offset++) {
            int num = 0;
            for (int i = 0; i < digits.size(); i++) {
                int idx = (i + offset) % digits.size();
                num += pow(10, i) * digits[idx];
            }
            circ_nums.insert(num);
            seen[num] = 1;
            circ_prime &= is_prime(num);
        }
        print_set(circ_nums);

        if (circ_prime == 1) {
            circular_primes += circ_nums.size();
        }
    }

    cout << "Total: " << circular_primes << endl;

    return 0;
}