#include <bits/stdc++.h>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    int d[n][n]; 

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }


    vector<int> ans;
    vector<bool> used(n, false);

    for (int k = 0; k < n; k++) {
        int el = a[k];
        used[el] = true;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][j] > d[i][el] + d[el][j]) {
                    d[i][j] = d[i][el] + d[el][j];
                }
            }
        }

        int mx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (used[i] && used[j]) {
                    mx = max(mx, d[i][j]); 
                }
            }
        }
        ans.push_back(mx);
    }

    for (int i = 0; i < ans.size(); i++) 
    	cout << ans[i] << "\n";

    return 0;
}
