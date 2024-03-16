#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

int main(){
    int n, m;
    cin >> n >> m;
    
    vector <pair<ll, pii>> g;

    while(m--){
        int l, r;
        ll w;
        cin >> l >> r >> w;

        g.pb(mp(w, mp(l, r)));
    }

    sort(g.begin(), g.end());
    int cnt = 2;
    ll mst = 0;

    while(cnt <= n){
        for(auto p : g){
            int a = p.second.first, b = p.second.second, c = p.first;

            if(a < cnt && cnt <= b){
                cnt++;
                mst += c;
                break;
            }
        }
    }

    cout << mst;
    return 0;
}
