#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& adjList, vector<bool>& visited, int start) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

bool isConnected(vector<vector<int>>& adjList, int start, int end) {
    vector<bool> visited(adjList.size(), false);
    bfs(adjList, visited, start);

    return visited[end];
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adjList[x].push_back(y);
        adjList[y].push_back(x);
    }

    int s, f;
    cin >> s >> f;

    if (isConnected(adjList, s, f)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

