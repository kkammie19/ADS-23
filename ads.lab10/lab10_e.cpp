#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<vector<int>> adjacencyMatrix(n + 1, vector<int>(n + 1));

    // Input adjacency matrix
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> adjacencyMatrix[i][j];
        }
    }

    // Process queries
    for (int i = 0; i < q; ++i) {
        int element1, element2, element3;
        cin >> element1 >> element2 >> element3;

        if (adjacencyMatrix[element1][element2] && adjacencyMatrix[element2][element3] && adjacencyMatrix[element1][element3]) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}

