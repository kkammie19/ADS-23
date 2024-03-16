#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canDeliver(const vector<int>& islands, int capacity, int flights) {
    int totalFlights = 0;
    for (int i = 0; i < islands.size(); i++) {
        totalFlights += (islands[i] + capacity - 1) / capacity;
    }
    return totalFlights <= flights;
}

int findLeastCapacity(const vector<int>& islands, int flights) {
    int left = 1;
    int right = *max_element(islands.begin(), islands.end());

    while (left < right) {
        int mid = left + (right - left) / 2;
        if (canDeliver(islands, mid, flights)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n, f;
    cin >> n >> f;
    vector<int> islands(n);

    for (int i = 0; i < n; i++) {
        cin >> islands[i];
    }

    int result = findLeastCapacity(islands, f);
    cout << result << endl;

    return 0;
}

