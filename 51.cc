#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include "utils.h"
using namespace std;

map<int, bool> primes;

int best = 0;
int best_candidate = 999999999;
set<int> best_family;
vector<int> best_choose;

inline void D(vector<int> &choose, string &candidate, int choose_count) 
{
    if (choose.size() == choose_count) {
        int cand = atoi(candidate.data());
        set<int> family = {};
        for (int j = 0; j < 9+1; j++) {
            if (j == 0 && choose[0] == 0) {
                continue;
            }

            char tmp[candidate.size()];
            memcpy(tmp, candidate.data(), candidate.size() * sizeof(char));

            for (int &i : choose) {
                tmp[i] = INT_TO_ASCII(j);
            }

            int a = atoi(tmp);
            if (primes.find(a) != primes.end()) {
               family.insert(a);
            }
        }

        if (family.size() == 8) {
            best = family.size();
            // 51 asks for the smallest value in the family
            // not the smallest prime that produces the family
            best_candidate = set_min(family);
            best_family = family;
            best_choose = choose;
        }

        cout << "SIZE: " << family.size() << " : ";
        print_set(family);
        return;
    }

    int cur;
    if (choose.size() == 0) {
        cur = -1;
    } else {
        cur = choose[choose.size() - 1];
    }

    for (int i = cur+1; i < candidate.size(); i++) {
        vector<int> tmp = choose;
        tmp.push_back(i);
        D(tmp, candidate, choose_count);
    }
}

int main()
{
    ifstream in("primes.txt");
    if (!in) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    int n;
    while (in >> n) {
        if (n > 1000000) {
            break;
        }
        primes[n] = true;
    }

    in.close();

    for (auto it = primes.begin(); it != primes.end(); ++it) {
        string candidate = to_string(it->first);
        vector<int> choose;
        choose.reserve(5);
        assert(choose.size() == 0);

        for (int t = 1; t < candidate.size(); t++) {
            D(choose, candidate, t);
        }
        if (best != 0) {
            break;
        } 
    }

    puts("BEST ------------------------------------------------");
    cout << "FOUND: " << best_candidate << '\n';
    cout << "FAMILY: ";
    print_set(best_family);
    cout << "CHOOSE: ";
    print_vector(best_choose);
    cout << "SIZE: " << best << endl;
}