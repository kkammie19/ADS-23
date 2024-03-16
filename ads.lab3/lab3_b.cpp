#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isPossible(vector<int>& ghouls, int n, int k, long long maxGhouls) {
    int blocks = 0;
    long long currentSum = 0;
    
    for (int i = 0; i < n; i++) {
        if (ghouls[i] > maxGhouls) {
            return false;  // If a ghoul cannot fit in any block, it's not possible.
        }
        if (currentSum + ghouls[i] > maxGhouls) {
            blocks++;
            currentSum = 0;
        }
        currentSum += ghouls[i];
    }
    
    return blocks < k;
}

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> ghouls(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ghouls[i];
    }

    long long left = 1, right = 1e18, result = -1;
    
    while (left <= right) {
        long long mid = (left + right) / 2;
        if (isPossible(ghouls, n, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << result << endl;
    
    return 0;
}

