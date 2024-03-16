#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> row_seats(n);
    for (int i = 0; i < n; i++) {
        cin >> row_seats[i];
    }

    sort(row_seats.begin(), row_seats.end());

    long long total_revenue = 0;

    for (int i = 0; i < n; i++) {
        int tickets_sold = min(x, row_seats[i]);
        total_revenue += static_cast<long long>(tickets_sold * (2 * row_seats[i] - tickets_sold + 1)) / 2;
        x -= tickets_sold;

        if (x <= 0) {
            break;
        }
    }

    cout << total_revenue << endl;

    return 0;
}

