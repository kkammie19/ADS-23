#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

vector <int> g[N];

bool used[N];

int cnt = 0;

map <int, int> childrenCnt, pred;

void bfs(int v){
	used[v] = 1;
	
	queue <int> q;
	q.push(v);
	
	while(!q.empty()){
		int sz = q.size();
		
		for(int i = 0; i < sz; i++){
			int x = q.front();
			q.pop();
			
			int cur_cnt = 0;
			for(auto y : g[x]){
				if(!used[y]){
					used[y] = 1;
					q.push(y);
					cur_cnt++;
					
					pred[y] = x;
				}
			}
			childrenCnt[x] = cur_cnt;
		}
	}
}

bool check(int child, int parent){
	return childrenCnt[child] > childrenCnt[parent];
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int x, y;
		cin >> x >> y;

		g[x].push_back(y);
		g[y].push_back(x);
	}

	for(int i=1; i<=n; i++){
		if(!used[i]){
			cnt++;
			bfs(i);
		}
	}

	for(auto i : pred)
		if(check(i.first, i.second))
			cnt++;

	cout << cnt;
	return 0;
}
