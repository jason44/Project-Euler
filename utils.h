#include <iostream>
#include <chrono>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;

#ifndef CPP_UTILS
#define CPP_UTILS

#define IS_INTEGER(x) floor(x) == x ? true : false
#define INT_TO_ASCII(x) (char)(x+48)

template <typename T>
void print_vector(vector<T> &v);

template <typename T>
void print_set(set<T> &v);


template <typename T>
int vec_sum(vector<T> &v);

template <typename T>
int vec_min(vector<T> &v);

template <typename T>
int set_min(set<T> &s);

template <typename T>
int vec_max(vector<T> &v);

template <typename T>
int set_max(set<T> &s);

int is_prime(int n);

int is_prime2(int n);

void find_primes_to(int n);

vector<int> sieve_primes(const int n);

bool is_triangle(int n);

bool is_triangle2(int n);

bool is_square(int n);

bool is_square2(int n);

bool is_penta(int n);

bool is_hexa(int n);

bool is_hepta(int n);

bool is_octa(int n);

#endif