#include <iostream>
#include <vector>
using namespace std;

char findBalancedChar(int n, vector<char>& arr, char letter) {
    int left = 0;
    int right = n - 1;
    char result = arr[0];

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > letter) {
            result = arr[mid];
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    char letter;
    cin >> letter;

    char balancedChar = findBalancedChar(n, arr, letter);

    cout << balancedChar << endl;

    return 0;
}
