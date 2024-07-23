#include <iostream>
#include <cassert>
#include <vector>

using namespace std;

vector<int> coins = {200, 100, 50, 20, 10, 5, 2, 1};

int table[8] = {0, 0, 0, 0, 0, 0, 0, 0};

int partitions = 0;

inline int sum_table()
{
    int total = 0;
    for (int i = 0; i < coins.size(); i++) {
        total += coins[i]*table[i];
    }
    return total;
}

inline void print_table()
{
    for (int i = 0; i < 8; i++) {
        cout << table[i] << ", ";
    }
    puts("");
}

void D(int incrm_idx, int stop)
{
    if (incrm_idx == coins.size() - 1) {
        table[incrm_idx] = stop;
        print_table();
		assert(sum_table() == 200);
        partitions++;
		// reset for next iteration
		table[incrm_idx] = 0;
        return;
    }

    const int incrm = coins[incrm_idx];
    for (int i = stop/incrm; i >= 0; i--) {
        table[incrm_idx] = i;
        if (incrm*i == stop) {
           print_table();
		   assert(sum_table() == 200);
           partitions++; 
           continue;
        }

        D(incrm_idx + 1, stop-(incrm*i));  
    }
}

int main()
{
    D(0, 200);

    cout << partitions << endl;

    return 0;
}