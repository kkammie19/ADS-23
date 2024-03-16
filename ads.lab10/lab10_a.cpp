#include <iostream>
#include <queue>
#include <vector>
#define pb push_back
#define mp make_pair

int a[1000][1000];

using namespace std;

void bfs(queue<pair<int, int>> q, int n, int m, int & cnt){

	while(!q.empty()){
		int sz = q.size();

		for(int k=0; k<sz; k++){
			int i = q.front().first;
			int j = q.front().second;
			q.pop();

			if(i-1 >= 0 && a[i-1][j] == 1){
				a[i-1][j] = 2;
				q.push(mp(i-1, j));
			}
			if(i+1 < n && a[i+1][j] == 1){
				a[i+1][j] = 2;
				q.push(mp(i+1, j));
			}
			if(j-1 >= 0 && a[i][j-1] == 1){
				a[i][j-1] = 2;
				q.push(mp(i, j-1));
			}
			if(j+1 < m && a[i][j+1] == 1){
				a[i][j+1] = 2;
				q.push(mp(i, j+1));
			}
		}
		cnt++;
	}
}

bool noMushroom(int n, int m){
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			if(a[i][j] == 1)
				return 0;
	}
	return 1;
}

int main(){
	int n, m;
	cin >> n >> m;

	queue <pair<int, int>> marios;

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> a[i][j];

			if(a[i][j] == 2)
				marios.push(mp(i, j));
		}
	}

	if(marios.size() == 0 && noMushroom(n, m)){
		cout << 0;
		return 0;
	}
	else{
		int cnt = -1;
		bfs(marios, n, m, cnt);

		if(noMushroom(n, m))
			cout << cnt;
		else
			cout << -1;
	}

	return 0;
}
