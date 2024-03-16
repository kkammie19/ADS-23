#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }

    sort(points.begin(), points.end());
    
    int minDifference = abs(points[1] - points[0]);

    for (int i = 2; i < N; i++) {
        int difference = abs(points[i] - points[i - 1]);
        if (difference < minDifference) {
            minDifference = difference;
        }
    }

    for (int i = 1; i < N; i++) {
        if (abs(points[i] - points[i - 1]) == minDifference) {
            cout << points[i - 1] << " " << points[i] << " ";
        }
    }

    return 0;
}
