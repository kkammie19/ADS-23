#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e4 + 100;

int pred[N];
bool used[N];

void printPath(int start, int end) {
    vector<int> path;
    for (int i = end; i != -1; i = pred[i])
        path.push_back(i);

    cout << path.size() - 1 << '\n';
    for (int i = path.size() - 2; i >= 0; i--)
        cout << path[i] << ' ';
}

int main() {
    int a, b;
    cin >> a >> b;

    queue<int> q;
    q.push(a);

    while (!q.empty()) {
        int sz = q.size();

        while (sz--) {
            int v = q.front();
            q.pop();

            if (v == b) {
                pred[a] = -1;
                printPath(a, b);
                return 0;
            }

            if (v < 0 || v > 10000 || used[v])
                continue;

            used[v] = true;

            if (v - 1 > 0 && !used[v - 1]) {
                pred[v - 1] = v;
                q.push(v - 1);
            }
            if (v * 2 < 10000 && !used[v * 2]) {
                pred[v * 2] = v;
                q.push(v * 2);
            }
        }
    }

    return 0;
}

