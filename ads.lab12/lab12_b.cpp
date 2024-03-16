#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<vector<pair<int, int>>> g;
int dij(int start, int e){
	vector<int> d(n);
	vector<bool> vis(n);
	for(int i = 0; i < n; i++)d[i] = 1e9;
	d[start] = 0;
	priority_queue <pair<int, int>> q;
	    q.push(make_pair(0, start));
	    while(!q.empty()){
	    	int v = q.top().second, cur_d = - q.top().first;
	    	q.pop();
	    	if(cur_d > d[v]) continue;
	    	
	    	for(int j = 0; j < g[v].size(); j++){
	    		int to = g[v][j].first;
	    		int len = g[v][j].second;
	    		if(d[v] + len < d[to]){
	    			d[to] = d[v] + len;
	    			q.push(make_pair(-d[to], to));
				}
			}
		}
		return d[e];
}

int main(){
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		u--, v--;
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}
	
	int s, a, b, f;
	cin >> s >> a >> b >> f;
	s--, a--, b--, f--;
	long long path1 = dij(s, a) + dij(a, b) + dij(b, f);
	    long long path2 = dij(s, b) + dij(b, a) + dij(a, f);
		
	long long res = min(path1, path2);
	if(res >= 1e9){
		cout << -1 << endl;
	}	 
	else{
		cout << res << endl;
	}
	return 0;
}
