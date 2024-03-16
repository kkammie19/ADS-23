#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& bags, int K, int H) {
    long long total = 0;
    for (int i = 0; i < bags.size(); i++) {
        total += (bags[i] + K - 1) / K;
    }
    return total <= H;
}

int minStealingSpeed(vector<int>& bags, int H) {
    int left = 1;
    int right = *max_element(bags.begin(), bags.end());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (possible(bags, mid, H)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> bags(N);
    
    for (int i = 0; i < N; i++) {
        cin >> bags[i];
    }
    
    int result = minStealingSpeed(bags, H);
    cout << result << endl;
    
    return 0;
}

    