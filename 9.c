#include <stdio.h>
#include <math.h>

static int cond(int a, int b, int c) {
    if (a + b + c == 1000) {
        return 1;
    }
    return 0;
}

static int is_py_triple(int a, int b, int c) {
    if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        int product = a * b *c;
        printf("%i, %i, %i : %i\n", a, b, c, product);
        return 1;
    }
    return 0;
}

int main() {
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 1000; k++) {
                if (cond(i, j, k)) {
                    is_py_triple(i, j, k);
                }
            }
        }
    }    

}