#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>

vector<pair<int, pii>> edges;
int component[55];
int sz[55];

void make_set(int n) {
    for (int i = 1; i <= n; i++) {
        component[i] = i;
        sz[i] = i;
    }
}

int find(int a) {
    if (a == component[a])
        return a;

    return component[a] = find(component[a]);
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
        return;

    if (sz[b] > sz[a])
        swap(a, b);

    component[b] = a;
    sz[a] += sz[b];
}

int main() {
    int n;
    cin >> n;

    int a[n][n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (i != j) {
                edges.pb(mp(a[i][j], mp(i + 1, j + 1)));
            }
        }
    }

    make_set(n);
    sort(edges.begin(), edges.end());

    int mst_sum = 0;
    for (auto e : edges) {
        int a = e.second.first, b = e.second.second, c = e.first;

        if (find(a) != find(b)) {
            mst_sum += c;
            unite(a, b);
        }
    }

    cout << mst_sum;

    return 0;
}

