#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_SIZE = 100;

int used[MAX_SIZE][MAX_SIZE];
char g[MAX_SIZE][MAX_SIZE];

void bfs(int row, int col, int n, int m) {
    queue<pair<int, int>> q;
    q.push({row, col});
    used[row][col] = 1;

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (const auto& dir : directions) {
            int newI = i + dir.first;
            int newJ = j + dir.second;

            if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && g[newI][newJ] == '1' && !used[newI][newJ]) {
                used[newI][newJ] = 1;
                q.push({newI, newJ});
            }
        }
    }
}

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> g[i][j];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!used[i][j] && g[i][j] == '1') {
                bfs(i, j, n, m);
                ++cnt;
            }
        }
    }

    cout << cnt;

    return 0;
}

