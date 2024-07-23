#include <iostream>
#include <vector>
#include <cstdint>
#include <algorithm>
#include <set>

using namespace std;

static inline bool is_perfect(uint32_t n)
{
    uint32_t div_sum = 0;
    if (n & 1) {
        for (uint32_t i = 1; i < n/2; i += 2) {
            if (n % i == 0) div_sum += i;
        }
    } else {
        for (uint32_t i = 1; i < n/2 + 1; i++) {
            if (n % i == 0) div_sum += i;
        }
    }
    if (div_sum > n) return true;

    return false;
}

int main()
{
    vector<uint32_t> ab_nums;
    for (uint32_t n = 12; n < 28123 - 12 + 2; n++) {
        if (is_perfect(n)) ab_nums.push_back(n);
    }

    for (uint32_t &am : ab_nums) {
        cout << am << ", ";
    } puts("");

    uint32_t total_sum = 0;
    for (int i = 1; i <= 28123; i++) {
        total_sum += i;
    }

    set<uint32_t> ab_nums_set;
    for (int i = 0; i < ab_nums.size(); i++) {
        for (int j = i; j < ab_nums.size(); j++) {
            uint32_t ab_num = ab_nums[i] + ab_nums[j];
            if (ab_num <= 28123)
                ab_nums_set.insert(ab_num);
        }
    }

    uint32_t ab_sum = 0;
    for (auto n : ab_nums_set) {
        ab_sum += n;
    }
    cout << total_sum << ", " << ab_sum << '\n';
    cout << total_sum - ab_sum << '\n';
    return 0;
}