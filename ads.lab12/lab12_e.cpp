#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = 100000;

bool bellmanFord(int start, int n, const vector<vector<int>>& graph, vector<int>& distance, vector<int>& parent) {
    distance[start] = 0;
    int lastRelaxationVertex;

    for (int i = 0; i < n; ++i) {
        lastRelaxationVertex = -1;
        for (int u = 0; u < n; ++u) {
            for (int v = 0; v < n; ++v) {
                if (graph[u][v] != INF && distance[u] + graph[u][v] < distance[v]) {
                    distance[v] = distance[u] + graph[u][v];
                    parent[v] = u;
                    lastRelaxationVertex = v;
                }
            }
        }
    }

    return (lastRelaxationVertex != -1);
}

void printCycle(int start, const vector<int>& parent) {
    vector<bool> visited(parent.size(), false);
    int current = start;

    while (!visited[current]) {
        cout << current + 1 << " ";
        visited[current] = true;
        current = parent[current];
    }

    cout << current + 1 << " " << endl;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n));
    vector<int> distance(n, INF);
    vector<int> parent(n, -1);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
            if (graph[i][j] == 100000) {
                graph[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<int> tempDistance = distance;
        vector<int> tempParent = parent;

        if (bellmanFord(i, n, graph, tempDistance, tempParent)) {
            cout << "YES" << endl;
            printCycle(i, tempParent);
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}







