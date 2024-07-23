#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    int dim = 1;
    int diagonal_sum = 1;
    int cur = 1;
    for (int i = 1; i < 500 + 1; i++) {
        for (int j = 0; j < 4; j++) {
            cur = cur + 2*i;
            cout << cur << '\n';
            diagonal_sum += cur; 
        }
        dim += 2;
    }

    assert(dim == 1001);
    cout << "FINAL SUM: " << diagonal_sum << endl;

    return 0;
}
