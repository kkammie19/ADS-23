#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair

const int N = 1010;
const int INF = (int)1e8;

vector<pii> coord;
vector<pii> g[N];
vector<int> d(N, INF);

int used[N];

int main(){
	int n;
	cin >> n;

	for(int i=0; i<n; i++){
		int x, y;
		cin >> x >> y;

		coord.pb(mp(x, y));
	}

	for(int i=0; i<n; i++){
		int x1 = coord[i].first, y1 = coord[i].second;
		for(int j=0; j<n; j++){
			if(i != j){
				int x2 = coord[j].first, y2 = coord[j].second;

				g[i].pb(mp(abs(x1 - x2) + abs(y1 - y2), j));
			}
		}
	}

	d[0] = 0;
	for(int i=0; i<n; i++){
		int v = -1;
		for(int j=0; j<n; j++)
			if(!used[j] && (v == -1 || d[j] < d[v]))
				v = j;

		if(d[v] == INF)
			break;
		used[v] = 1;

		for(auto p : g[v]){
			int u = p.second, w = p.first;

			if(d[u] == INF || max(w, d[v]) < d[u])
				d[u] = max(w, d[v]);
		}
	}

	cout << d[n-1];
	return 0;
}
