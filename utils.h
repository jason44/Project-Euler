#include <iostream>
#include <chrono>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

#define IS_INTEGER(x) floor(x) == x ? true : false

inline int is_prime(int n)
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

inline int is_prime2(int n)
{
    for (int i = 3; i < n/2; i += 2) {
        if (n % i == 0) {
            return 0;
        }
    }

    return 1;
}

void find_primes_to(int n)
{
    for (int i = 3; i < n; i += 2)
    {
        if (is_prime(i)) {
            cout << i << '\n';
        }
    }
}


template <typename T>
inline void print_vector(vector<T> &v) 
{
    for (auto &c : v) {
        cout << c << ", ";
    }
    puts("");
}

template <typename T>
inline void print_set(set<T> &v) 
{
    for (auto &c : v) {
        cout << c << ", ";
    }
    puts("");
}

/*
    start = 0
    if (n & 1): start = 3
    else: start = 2
    for d in range(start, n//2 + 1, 2):
        q = n // d
        if q == d and d*(q) == n:
            return True
    return False
*/
inline bool is_square(int n) 
{
    if (n == 1) return true;
    int start = 0;
    if (n & 1) {
        start = 3;
    } else {
        start = 2;
    }

    for (int d = start; d < n / 2 + 1; d += 2) {
        int q = n / d;
        if (q == d && (q * d) == n) {
            return true;
        }
    }
    return false;
}

template <typename T>
inline int vec_sum(vector<T> &v) {
    T total = 0;
    for (auto &t : v) {
        total += t;
    }

    return total;
}