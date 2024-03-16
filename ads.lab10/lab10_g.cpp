#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

const int MAXN = 505;

vector<int> g[MAXN];
int mark[MAXN];
vector<int> cyclePath;
stack<int> st;
bool cycle = false;

void dfs(int v) {
    st.push(v);
    mark[v] = 1;

    for (auto adj : g[v]) {
        if (mark[adj] == 0) {
            dfs(adj);
        } else if (mark[adj] == 1 && !cycle) {
            cycle = true;

            while (st.top() != adj) {
                cyclePath.push_back(st.top());
                st.pop();
            }

            cyclePath.push_back(adj);
            cyclePath.push_back(v);
            reverse(cyclePath.begin(), cyclePath.end());

            return;
        }
    }

    mark[v] = 2;

    if (!st.empty())
        st.pop();
}

void dfs2(int v, int sour, int dest, bool &cycleFound) {
    mark[v] = 1;

    for (auto adj : g[v]) {
        if (v == sour && adj == dest)
            continue;

        if (mark[adj] == 0) {
            dfs2(adj, sour, dest, cycleFound);
        } else if (mark[adj] == 1) {
            cycleFound = true;
            return;
        }
    }

    mark[v] = 2;
}

int main() {
    int n, m;
    cin >> n >> m;

    while (m--) {
        int x, y;
        cin >> x >> y;

        g[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (mark[i] == 0)
            dfs(i);

        if (cycle)
            break;
    }

    if (!cycle) {
        cout << "YES";
        return 0;
    }

    for (int i = 1; i < cyclePath.size(); i++) {
        int sour = cyclePath[i - 1], dest = cyclePath[i];

        for (int j = 1; j <= n; j++)
            mark[j] = 0;

        bool cycleFound = false;

        for (int j = 1; j <= n; j++) {
            if (mark[j] == 0)
                dfs2(j, sour, dest, cycleFound);
        }

        if (!cycleFound) {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";

    return 0;
}


