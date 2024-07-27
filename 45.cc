#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

#define IS_INTEGER(x) floor(x) == x ? true : false

using namespace std;

inline bool is_triangular(int64_t N)
{
    double n = (sqrt(8*N + 1) - 1) / 2;
    return IS_INTEGER(n);
}

inline int64_t triangular(int64_t n)
{
    return n * (n + 1) / 2;
}

inline bool is_pentagonal(int64_t N)
{
    double n = (sqrt(24*N + 1) + 1) / 6;
    return IS_INTEGER(n);
}

inline int64_t pentagonal(int64_t n)
{
    return n * (3*n - 1) / 2;
}

inline bool is_hexagonal(int64_t N)
{
    double n = (sqrt(8*N + 1) + 1) / 4;
    return IS_INTEGER(n);
}

inline int64_t hexagonal(int64_t n)
{
    return n * (2*n - 1);
}

int main()
{
    int64_t n = 286;
    int64_t num = 0;
    int64_t T = triangular(285);
    assert(is_pentagonal(T) && is_hexagonal(T));
    while (num == 0) {
        T = triangular(n);
        cout << T << '\n';
        if (is_pentagonal(T) && is_hexagonal(T)) {
            num = T;
        }
        n++;
        /*
        assert(is_triangular(triangular(n)));
        assert(is_pentagonal(pentagonal(n)));
        assert(is_hexagonal(hexagonal(n)));
        */

    }
    cout << "FOUND: " << num << endl;
    return 0;
}
