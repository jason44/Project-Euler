#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>

#ifdef PYBIND
#include <pybind11/pybind11.h>
#endif

using namespace std;

#define IS_INTEGER(x) floor(x) == x ? true : false
#define INT_TO_ASCII(x) (char)(x + 48)

// MACOS: for pybind
// clang++ -O3 -DPYBIND -Wall -shared -std=c++11 -undefined dynamic_lookup
// `python3 -m pybind11 --includes` utils.cc -o cpp_utils`python3-config
// --extension-suffix`

template <typename T>
inline void print_vector(vector<T> &v) 
{
    cout << "[ ";
    for (auto &c : v) {
        cout << c << ", ";
    }
    puts(" ]");
}

template <typename T>
inline void print_set(set<T> &v) 
{
    cout << "{";
    for (auto &c : v) {
        cout << c << ", ";
    }
    puts("}");
}

template <typename T>
inline int vec_sum(vector<T> &v) 
{
    T total = 0;
    for (auto &t : v) {
        total += t;
    }

    return total;
}

template <typename T>
inline int vec_min(vector<T> &v) 
{
    T min = 99999999;
    for (auto &t : v) {
        if (t < min) {
            min = t;
        }
    }
    return min;
}

template <typename T>
inline int set_min(set<T> &s) 
{
    T min = 99999999;
    for (auto &t : s) {
        if (t < min) {
            min = t;
        }
    }
    return min;
}

template <typename T>
inline int vec_max(vector<T> &v) 
{
    T max = 0;
    for (auto &t : v) {
        if (t > max) {
            max = t;
        }
    }
    return max;
}

template <typename T>
inline int set_max(set<T> &s) 
{
    T max = 0;
    for (auto &t : s) {
        if (t > max) {
            max = t;
        }
    }
    return max;
}

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
        for (int i = 3; i < n / 2; i += 2) {
            if (n % i == 0) {
                return 0;
            }
        }
    } else {
        return 0;
    }
    return 1;
}

// theorem: any prime number > 3 can be written as the sum 6k +- 1
// theorem: no number has factors greater than its square root
inline bool is_prime2(uint64_t n) 
{
    if (n <= 1) return false;
    if (n <= 3) return true;
    if ((n % 2 == 0) || (n % 3 == 0)) return false;
    uint64_t i = 5;
    while (i * i <= n) {
        if ((n % i == 0) || (n % (i + 2) == 0)) return false;
        i += 6;
    }
    return true;
}

void find_primes_to(int n) 
{
    for (int i = 3; i < n; i += 2) {
        if (is_prime(i)) {
            cout << i << '\n';
        }
    }
}

vector<int> sieve_primes(const int n)
{
    vector<int> prime_nums;
    bool *mask = (bool *)malloc(sizeof(bool) * n + 1);
    memset(mask, true, sizeof(bool) * n + 1);
    mask[0] = false;
    mask[1] = false;

    for (int i = 2; i < static_cast<int>(sqrt(n)); i++) {
        if (mask[i]) {
            int desc = static_cast<int>(pow(i, 2));
            do {
                mask[desc] = false;
                desc += i;
            } while (desc <= n);
        }
    }
    for (int i = 0; i < n; i++) {
        if (mask[i]) {
            prime_nums.push_back(i);
        }
    }

    free(mask);
    return prime_nums;
}

inline bool is_triangle(int n) {
    n *= 2;
    int k = 1;
    while (true) {
        int tmp = k * k + k;
        if (tmp == n) {
            return true;
        }
        if (tmp > n) {
            return false;
        }
        k++;
    }
}

inline bool is_triangle2(int n) 
{
    int i = 1;
    while (n > 0) {
        n -= i;
        i++;
    }
    if (n == 0) {
        return true;
    }
    return false;
}

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

inline bool is_square2(int n)
{
    int sqrt_n = static_cast<int>(sqrt(n));
    if (sqrt_n * sqrt_n == n) {
        return true;
    }
    return false;
}

inline bool is_penta(int n) 
{
    n *= 2;
    int k = 1;
    while (true) {
        int tmp = 3 * k * k - k;
        if (tmp == n) {
            return true;
        }
        if (tmp > n) {
            return false;
        }
        k++;
    }
}

inline bool is_hexa(int n) 
{
    int k = 1;
    while (true) {
        int tmp = 2 * k * k - k;
        if (tmp == n) {
            return true;
        }
        if (tmp > n) {
            return false;
        }
        k++;
    }
}

inline bool is_hepta(int n) 
{
    n *= 2;
    int k = 1;
    while (true) {
        int tmp = 5 * k * k - 3 * k;
        if (tmp == n) {
            return true;
        }
        if (tmp > n) {
            return false;
        }
        k++;
    }
}

inline bool is_octa(int n) 
{
    int k = 1;
    while (true) {
        int tmp = 3 * k * k - 2 * k;
        if (tmp == n) {
            return true;
        }
        if (tmp > n) {
            return false;
        }
        k++;
    }
}


#ifdef PYBIND
PYBIND11_MODULE(cpp_utils, m) {
    m.def("is_prime2", &is_prime2, "Check if a number is prime");
    m.def("is_triangle", &is_triangle, "Check if a number is triangular");
    m.def("is_triangle2", &is_triangle2, "Check if a number is triangular");
    m.def("is_square", &is_square, "Check if a number is square");
    m.def("is_square2", &is_square2, "Check if a number is square");
    m.def("is_penta", &is_penta, "Check if a number is pentagonal");
    m.def("is_hexa", &is_hexa, "Check if a number is hexagonal");
    m.def("is_hepta", &is_hepta, "Check if a number is heptagonal");
    m.def("is_octa", &is_octa, "Check if a number is octagonal");
}
#endif