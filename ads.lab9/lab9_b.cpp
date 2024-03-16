#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, T;
    int K;
    cin >> s >> K;
    cin.ignore(); // Ignore the newline character
    getline(cin, T);

    size_t found = 0;
    int count = 0;
    size_t pos = 0;

    while ((found = T.find(s, pos)) != string::npos) {
        count++;
        if (count >= K) {
            cout << "YES" << endl;
            return 0;
        }
        pos = found + 1;
    }

    cout << "NO" << endl;

    return 0;
}

