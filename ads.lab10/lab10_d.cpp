#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e8;

int n, m, q;

vector <int> g[5050];
vector <int> d(5050, N);

void bfs(int v){
	d[v] = 0; 
	
	queue <int> q;
	q.push(v);
	
	while(!q.empty()){
		int x = q.front();
		q.pop();
		
		for(auto y : g[x]){
			if(d[y] > d[x] + 1){
				q.push(y);
				d[y] = d[x] + 1;
			}
		}
	}
}

int main(){
	cin >> n >> m >> q;
	
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	while(q--){
		int type, v;
		cin >> type >> v;
		
		if(type == 1){
			bfs(v);
		}
		else{
			if(d[v] == N){
				cout << -1 <<'\n';
			}
			else{
				cout << d[v] << '\n';
			}
		}
	}
}
