#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>

vector<pair<int, pii>> edges;
int component[1010];
int sz[1010];

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

void addRoad(int a, int b, int c, int cost) {
    edges.pb(mp(c * cost, mp(a, b)));
}

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int mini = min(x, y);

    while (m--) {
        string s;
        int a, b, c;

        cin >> s >> a >> b >> c;

        if (s == "big") {
            addRoad(a, b, x, c);
        } else if (s == "small") {
            addRoad(a, b, y, c);
        } else {
            addRoad(a, b, mini, c);
        }
    }

    sort(edges.begin(), edges.end());
    make_set(n);

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

