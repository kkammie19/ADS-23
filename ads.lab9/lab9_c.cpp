#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computePrefixFunction(const string& s) {
    int n = s.length();
    vector<int> prefix(n, 0);
    int j = 0;
    
    for (int i = 1; i < n; i++) {
        while (j > 0 && s[i] != s[j]) {
            j = prefix[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        prefix[i] = j;
    }
    return prefix;
}

int findCyclicShift(const string& tamerlanLine, const string& alikhanLine) {
    string concatenated = alikhanLine + alikhanLine;
    vector<int> prefix = computePrefixFunction(tamerlanLine);
    int j = 0;
    
    for (int i = 0; i < concatenated.length(); i++) {
        while (j > 0 && concatenated[i] != tamerlanLine[j]) {
            j = prefix[j - 1];
        }
        if (concatenated[i] == tamerlanLine[j]) {
            j++;
        }
        if (j == tamerlanLine.length()) {
            return i - j + 1;
        }
    }
    
    return -1;
}

int main() {
    string tamerlanLine, alikhanLine;
    cin >> tamerlanLine >> alikhanLine;

    int result = findCyclicShift(tamerlanLine, alikhanLine);
    cout << result << endl;

    return 0;
}

