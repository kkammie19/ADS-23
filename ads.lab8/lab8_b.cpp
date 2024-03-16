#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<size_t, size_t> mp;
size_t cnt = 0;

void count(const string& t, const string& s) {
    int n = t.size();
    int m = s.size();

    long long h[n];
    long long p[n];

    long long q = 1e9 + 7;

    p[0] = 1;
    for (int i = 1; i < n; ++i) {
        p[i] = (p[i - 1] * 31) % q;
    }

    h[0] = ((t[0] - 'a' + 1) * p[0]) % q;
    for (int i = 1; i < n; ++i) {
        h[i] = (h[i - 1] + ((t[i] - 'a' + 1) * p[i]) % q) % q;
    }

    long long h_s = 0;
    for (int i = 0; i < m; ++i) {
        h_s = (h_s + ((s[i] - 'a' + 1) * p[i]) % q) % q;
    }

    for (int i = 0; i + m - 1 < n; i++) {
        long long dif = h[i + m - 1];
        if (i > 0) {
            dif = (dif - h[i - 1] + q) % q;
        }
        if (dif == (h_s * p[i]) % q) {
            mp[i]++;
            if (mp[i] == 2) {
                cnt++;
            }
        }
    }
}

int main() {
    string s1, s2, pattern;
    cin >> s1 >> s2 >> pattern;

    count(s1, pattern);
    count(s2, pattern);

    cout << cnt;

    return 0;
}
