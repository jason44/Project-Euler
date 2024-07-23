#include <iostream>
#include <map>
using namespace std;

map<unsigned int, unsigned int> pairs{};

unsigned int divisor_sum(const unsigned int m)
{
    if (m & 1) {
        unsigned int sum = 1;
        for (int i = 3; i < m / 2; i += 2) {
            if (m % i == 0) sum += i;
        }
        return sum;
    } else {
        unsigned int sum = 0;
        for (int i = 1; i < (m / 2) + 1; i++) {
            if (m % i == 0) sum += i;
        }
        return sum;
    }
}

int main()
{
    for (int i = 1; i < 10000; i++) {
        //cout << divisor_sum(i) << '\n';
        pairs[i] = divisor_sum(i);
    }
    unsigned int sum = 0;
    for (auto &p : pairs) {
        if (p.first != p.second) {
            if (p.first == pairs[p.second]) {
                // divide bv 2 to account for the fact that each pair is counted twice
                // THEOREM: all amicable numbers are even
                sum += p.first/2;
                sum += p.second/2;
                cout << "amicable: " << p.first << ", " << p.second << '\n';
            }
        }
    }
    cout << "Final: " << sum << endl;
    return 0;
}

