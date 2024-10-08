#include <iostream>
#include <fstream>
#include <vector>
#include "utils.h"
using namespace std;

int main() 
{
    vector<int> primes = sieve_primes(1000000);

    ofstream of("primes.txt");
    if (!of) {
        cerr << "Error opening file for writing" << endl;
        return 1;
    }

    for (int p : primes) {
        of << p << " ";
    }

    of.close();

    cout << "Primes written to file successfully." << endl;

    vector<int> numbers;

    ifstream in("primes.txt");
    if (!in) {
        cerr << "Error opening file for reading" << endl;
        return 1;
    }

    int n;
    while (in >> n) {
        numbers.push_back(n);
    }

    in.close();

    cout << "Primes read from file:" << endl;
    for (int n : numbers) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}