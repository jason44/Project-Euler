#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_map>
#include <cctype>
using namespace std;

unordered_map<string, unsigned long long> cube_count;
unordered_map<string, unsigned long long> lowest;

int main() 
{
    for (unsigned long long i = 0; i < 21000; i++) {
        unsigned long long cube = i * i * i;
        string sc = to_string(cube);
        sort(sc.begin(), sc.end());
        
        if (cube_count.find(sc) == cube_count.end()) {
            cube_count[sc] = 1;
        } else {
            cube_count[sc]++;
        }

        if (lowest.find(sc) == lowest.end()) {
            lowest[sc] = cube;
        }
    }
    unsigned long long best = numeric_limits<unsigned long long>::max();
    for (auto it = cube_count.begin(); it != cube_count.end(); it++) {
        if (it->second > 4) {
            //cout << "str: " << it->first << '\n';
            cout << it->second << " : " << lowest[it->first] << '\n';
            cout << "n : " << cbrt(lowest[it->first]) << '\n';
            if (lowest[it->first] < best) {
                best = lowest[it->first];
            }
        }
    }
    cout << "BEST: " << best << endl;
    return 0;
}