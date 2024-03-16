#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> prefix_function(string s) {
    vector<int> pr(s.length());
    for (int i = 1; i < s.length(); i++) {
        int j = pr[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pr[j - 1];
        if (s[i] == s[j])
            j++;
        pr[i] = j;
    }
    return pr;
}

vector<int> kmp(string text, string pattern) {
    vector<int> occurrences;
    string concat = pattern + '%' + text;
    vector<int> pr = prefix_function(concat);
    for (int i = pattern.size() + 1; i < concat.size(); i++) {
        if (pr[i] == pattern.size()) {
            occurrences.push_back(i - 2 * pattern.size());
        }
    }
    return occurrences;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string text, pattern;
        int k;
        cin >> text >> k;
        vector<int> pi = prefix_function(text);
        int last = pi[text.size() - 1];
        cout << (text.size() - last) * k + last << endl;
    }

    return 0;
}

