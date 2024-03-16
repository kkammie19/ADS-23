#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define pb push_back
#define mp make_pair

const int INF = (int)1e7;

int n, m;
int used[444][444];

void printWay(vector <pii> * g){
	for(int i = 1; i <= n; i++){
		for(auto p : g[i])
			cout << i << ' ' << p.second << '\n';
	}
}

int getTime(vector <pii> * g){
	vector <int> d(444, INF);
	d[1] = 0;

	priority_queue <pii> pq;
	pq.push(make_pair(-0, 1));

	while(!pq.empty()){
		pii p = pq.top();
		pq.pop();

		int dv = p.first, v = p.second;

		if(dv > d[v]){
			continue;
        }
		
		for(auto p : g[v]){
			int w = p.first, u = p.second;
			if(d[u] > d[v] + w){
				d[u] = d[v] + w;
				pq.push(mp(-d[u], u));
			}
		}
	}

	return d[n];
}

int main(){
	vector <pii> air[444], road[444];

	cin >> n >> m;

	for(int i = 1; i <= m; i++){
		int x, y;
		cin >> x >> y;

		air[x].pb(mp(1, y));
		air[y].pb(mp(1, x));

		used[x][y] = 1;
		used[y][x] = 1;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(!used[i][j] && i != j){
				used[i][j] = 1;
				road[i].pb(mp(1, j));
			}
		}
	}



	if(air[1].size() == 0 || air[n].size() == 0 || road[1].size() == 0 || road[n].size() == 0){
		cout << -1;
		return -0;
	}

	cout << max(getTime(air), getTime(road));
	return 0;
}
