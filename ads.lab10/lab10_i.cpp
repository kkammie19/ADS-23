#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 10;

vector <int> g[N];
vector <int> order(N);

bool used[N];

bool possible = true;

void dfs(int source, int v, int & i){
	used[v] = 1;
	for(auto adj : g[v]){
		if(!used[adj]){
			dfs(source, adj, i);
		}
		else{
			if(adj == source){
				possible = false;
				return;
			}
		}
	}

	order[i--] = v;
}

int main(){
	int n, m;
	cin >> n >> m;

	while(m--){
		int i, j;
		cin >> i >> j;
		i--;
		j--;
		g[i].push_back(j);
	}

	int ind = n-1;
	for(int i=0; i<n; i++){
		if(!used[i])
			dfs(i, i, ind);

		if(!possible)
			break;
	}

	if(possible){
		cout << "Possible" << '\n';
		for(int i=0; i<n; i++)
			cout << order[i] + 1 << ' ';
	}
	else{
		cout << "Impossible";
	}

	return 0;
}
