#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> competitors(N);
    
    for (int i = 0; i < N; i++) {
        cin >> competitors[i];
    }
    
    int P;
    cin >> P;
    
    vector<int> rounds(P);
    
    for (int i = 0; i < P; i++) {
        cin >> rounds[i];
    }

    // Sort competitors in ascending order
    sort(competitors.begin(), competitors.end());
    
    int currentRound = 0;
    
    for (int i = 0; i < P; i++) {
        int power = rounds[i];
        
        // Binary search to find the number of competitors Mark can defeat
        int left = 0, right = N - 1, markCount = 0;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (competitors[mid] <= power) {
                markCount = mid + 1;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        // Calculate the total power of defeated competitors
        long long totalPower = 0;
        for (int j = 0; j < markCount; j++) {
            totalPower += competitors[j];
        }
        
        cout << markCount << " " << totalPower << endl;
    }
    
    return 0;
}

