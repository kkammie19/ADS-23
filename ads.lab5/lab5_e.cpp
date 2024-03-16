#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int q, k;
    cin >> q >> k;

    priority_queue<long long, vector<long long>, greater<long long>> min_heap;
    long long total_cookies = 0;

    for (int i = 0; i < q; i++) {
        string command;
        cin >> command;

        if (command == "insert") {
            long long n;
            cin >> n;
            min_heap.push(n);
            total_cookies += n;

            if (min_heap.size() > k) {
                total_cookies -= min_heap.top();
                min_heap.pop();
            }
        } else if (command == "print") {
            cout << total_cookies << endl;
        }
    }

    return 0;
}

