#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

string findLongestCommonSubstring(const vector<string>& strings) {
    int K = strings.size();
    int minLen = strings[0].size();

    for (const string& s : strings) {
        minLen = min(minLen, static_cast<int>(s.length()));
    }

    string commonSubstring = "";
    unordered_map<string, int> substringCounts;

    for (int len = minLen; len > 0; len--) {
        for (int i = 0; i <= minLen - len; i++) {
            string sub = strings[0].substr(i, len);
            bool isCommon = true;

            for (int j = 1; j < K; j++) {
                if (strings[j].find(sub) == string::npos) {
                    isCommon = false;
                    break;
                }
            }

            if (isCommon) {
                commonSubstring = sub;
                return commonSubstring;
            }
        }
    }

    return commonSubstring;
}

int main() {
    int K;
    cin >> K;

    vector<string> strings(K);

    for (int i = 0; i < K; i++) {
        cin >> strings[i];
    }

    string commonSubstring = findLongestCommonSubstring(strings);

    cout << commonSubstring << endl;

    return 0;
}


