#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

const char start = 'a';
const char stop = 'z' + 1;

vector<string> split(const string &s, char delimiter) 
{
    vector<string> tokens;
    stringstream ss(s);
    string token;

    while (getline(ss, token, delimiter)) {
        tokens.push_back(token);
    }

    return tokens;
}

int main()
 {
    ifstream file("59_cipher.txt");
    
    if (!file.is_open()) {
        cerr << "Could not open the file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        vector<string> tokens = split(line, ',');
        string toks;
        
        for (const string &token : tokens) {
            toks.push_back(static_cast<char>(atoi(token.data())));
        }

        for (char i = start; i < stop; i++) {
            for (char j = start; j < stop; j++) {
                for (char k = start; k < stop; k++) {
                    char pswd[] = {i , j, k};
                    string out;
                    int idx = 0;
                    for (const char &tok : toks) {
                        //cout << (int)tok << " ";
                        out.push_back(tok ^ pswd[idx]);
                        idx = (idx + 1) % 3;

                    }

                    // an english sentence almost certainly has a large number of alphanumeric values
                    // compared to non-alphanumeric values.
                    int alphanum = 0;
                    for (char &c : out) {
                        if (c == ' ') alphanum++;
                        if (isalnum(static_cast<unsigned char>(c))) {
                            alphanum++;
                        }
                    }

                    if (static_cast<double>(alphanum) / out.size() > 0.95) {
                        cout << "KEY: " << i << j << k << " \n";
                        cout << out << "\n\n";
                        int sum = 0;
                        for (char &c : out) {
                            sum += (int)c;
                        }
                        cout << "SENTENCE SUM: " << sum << endl;
                    }
                }
            }

        }
        for (const char &tok : toks) {
            //cout << (int)tok << " ";

        }
        cout << endl;
    }

    file.close();
    return 0;
}