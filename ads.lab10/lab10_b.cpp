#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathLength(int n, vector<vector<int>>& graph, int start, int end) {
    vector<int> distance(n + 1, -1); // Initialize distances to -1 (unvisited)
    queue<int> q;

    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor = 1; neighbor <= n; ++neighbor) {
            if (graph[current][neighbor] == 1 && distance[neighbor] == -1) {
                distance[neighbor] = distance[current] + 1;
                q.push(neighbor);

                if (neighbor == end) {
                    return distance[neighbor];
                }
            }
        }
    }

    return -1; // No path found
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> graph[i][j];
        }
    }

    int start, end;
    cin >> start >> end;

    int result = shortestPathLength(n, graph, start, end);

    cout << result << endl;

    return 0;
}

