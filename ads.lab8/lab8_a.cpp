#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

long long MOD = 1e9 + 7;
long long X = 11;

string getHash(string s) {
    long long sumOfHash = 0;
    long long curX = 1;
    for (int i = 0; i < s.size(); i++) {
        long long curHash = (s[i] - 47) * curX % MOD;
        sumOfHash = (sumOfHash + curHash) % MOD;
        curX = (curX * X) % MOD;

        }
    return to_string(sumOfHash);
}

int main() {
    int n; cin >> n;
    vector <string> vec;
    unordered_map <string, int> map;


    for (int i = 0; i < n * 2; i++) {
        string s; cin >> s;
        vec.push_back(s);
        map[s] = 1;
    }

    int cnt=0;
    for (int i = 0; i < n * 2; i++) {
        string t = getHash(vec[i]);
        if(cnt == n) {
            break;
        }
        if(map[t] == 1) {
            cout << "Hash of string \"" << vec[i] << "\" is " << t << endl;
            cnt++;
        }
    }
}