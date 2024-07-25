#include <iostream>
#include <cassert>
#include "utils.h"

using namespace std;
const int stop = 1000000;
int total = 0;
int count = 0;

int main()
{
    int next_place = 100;
    int current_place = 10;
    for (int n = 11; count != 11; n += 2) {
        if (n > next_place) {
            next_place *= 10;
            current_place *= 10;
        }

        int prime = 1;
        int current = n;
        int tmp_place = current_place;

        while (current != 0) {
            prime &= is_prime(current);
            current -= (current / tmp_place) * tmp_place;
            tmp_place /= 10;
        }

        current = n;
        while (current != 0) {
            prime &= is_prime(current);
            current /= 10;
        }

        if (prime) {
            cout << n << '\n';
            total += n;
            count++;
        } 
    }

    cout << "TOTAL: " << total << endl; 
    return 0;
}