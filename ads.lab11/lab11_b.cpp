#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>

vector <pair<int, pii>> g;

int component[505];
int sz[505];

void make_set(int n){
	for(int i=1; i<=n; i++){
		component[i] = i;
		sz[i] = i;
	}
}

int find(int a){
	if(a == component[a])
		return a;

	return component[a] = find(component[a]);
}

void unite(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)
		return;

	if(sz[b] > sz[a])
		swap(a, b);

	component[b] = a;
	sz[a] += sz[b];
}

int main(){
	int n;
	cin >> n;

	int a[n];
	for(int i=0; i<n; i++)
		cin >> a[i];

	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++)
			g.pb(mp(a[i] + a[j], mp(i+1, j+1)));
	}

	// for(auto p : g)
	// 	cout << p.second.first << ' ' << p.second.second << " --> " << p.first << '\n';	

	make_set(n);
	sort(g.begin(), g.end());

	int mst_sum = 0;
	for(auto e : g){
		int a = e.second.first, b = e.second.second, c = e.first;

		if(find(a) != find(b)){
			mst_sum += c;

			unite(a, b);
		}
	}

	cout << mst_sum;

	return 0;
}
