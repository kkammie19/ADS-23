#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> numbers(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    int k;
    cin >> k;

    int nearest = numbers[0];  // Initialize nearest to the first number in the list
    int minDistance = abs(numbers[0] - k);
    int nearestIndex = 0;

    // Iterate through the list and find the nearest number to k
    for (int i = 1; i < n; ++i) {
        int distance = abs(numbers[i] - k);
        if (distance < minDistance) {
            nearest = numbers[i];
            minDistance = distance;
            nearestIndex = i;
        }
    }

    // Print the offset from the head of the list
    cout << nearestIndex << endl;

    return 0;
}
