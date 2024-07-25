#include <iostream>
#include <string>
#include <cstring>

using namespace std;
int prod = 1;

int main()
{
    int steps = 1;
    int current_place = 1; 
    int next_place = 10; 
    int current = 1;
    int counter = 0;
    for (int d = 1; d < 1000000 + 3; d++) {
        if (counter == steps) {
            current += 1;
            counter = 0;
        }
        cout << d << ": " << current << '\n';
        counter++;
        if (d == next_place) {
            string s = to_string(current);
            int idx = (d % steps) - 1;
            if (idx == -1) idx = steps - 1;
            int digit = stoi(s.substr(idx, 1));
            cout << "digit: " << digit << '\n';
            prod *= digit;
        }
        if (current >= next_place) {
            current_place *= 10;
            next_place *= 10;
            steps++;
        }
    }
    cout << "Product: " << prod << endl;
    return 0;
}


