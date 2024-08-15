#include <iostream>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;

#define IS_INTEGER(x) floor(x) == x ? true : false
#define INT_TO_ASCII(x) (char)(x+48)

template <typename T>
inline void print_vector(vector<T> &v);

template <typename T>
inline void print_set(set<T> &v);

inline bool is_square(int n);

template <typename T>
inline int vec_sum(vector<T> &v);

template <typename T>
inline int vec_min(vector<T> &v);

template <typename T>
inline int set_min(set<T> &s);

template <typename T>
inline int vec_max(vector<T> &v);

template <typename T>
inline int set_max(set<T> &s);

inline int is_prime(int n);

inline int is_prime2(int n);

void find_primes_to(int n);

vector<int> sieve_primes(const int n);

inline bool is_triangle(const int n);

inline bool is_square(const int n);

inline bool is_penta(const int n);

inline bool is_hexa(const int n);

inline bool is_hepta(const int n);

inline bool is_octa(const int n);