#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> densities(n);
    for (int i = 0; i < n; i++) {
        cin >> densities[i];
    }

    if (*max_element(densities.begin(), densities.end()) < m) {
        cout << -1 << endl;  // It's impossible to achieve density >= m.
        return 0;
    }

    // Create a priority queue to maintain densities in ascending order.
    priority_queue<int, vector<int>, greater<int>> pq(densities.begin(), densities.end());

    int operations = 0;
    while (pq.top() < m) {
        int least = pq.top();
        pq.pop();
        int second_least = pq.top();
        pq.pop();
        int new_density = least + 2 * second_least;
        pq.push(new_density);
        operations++;
    }

    cout << operations << endl;

    return 0;
}

