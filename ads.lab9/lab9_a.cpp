#include <bits/stdc++.h>
using namespace std;

vector<int> prefixFun(string s) {
    vector<int> pi(s.size());
    pi[0] = 0;
    for (int i = 1; i < s.size(); i++) {
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) {
            pi[i] = j + 1;
        } else {
            pi[i] = 0;
        }
    }

    return pi;
}

bool kmp(string s, string t) {
    s = t + '#' + s;
    vector<int> res;
    vector<int> pi = prefixFun(s);
    for (int i = 0; i < s.size(); i++) {
        if (pi[i] == t.size())return true;
    }
    return false;
}

int main() {
    string s, t;
    cin >> s >> t;
    
    int cnt = 1;

    string tmp = s;
    while(s.size() < t.size()){
        s += tmp;
        cnt++;
    }
    if(kmp(s, t)){
        cout << cnt;
    }
    else if(kmp(s + tmp, t)){
        cout << cnt + 1;
    }
    else cout << -1;
    return 0;
}
