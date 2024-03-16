#include <bits/stdc++.h>

using namespace std;

struct Pasture{
	int x1, x2;
	int y1, y2;
};

int getPasturesCount(vector<Pasture>& pastures, int x){
	int res = 0;
	for(auto & pasture : pastures){
		if(pasture.x1 <= x && pasture.y1 <= x && pasture.x2 <= x && pasture.y2 <=x){
			res ++;
		}
	}
	return res;
}

int main() {

    int n, k;
    cin >> n >> k;
    
    vector<Pasture> pastures(n);
    for(auto & pasture : pastures){
    	cin >> pasture.x1 >> pasture.y1 >> pasture.x2 >> pasture.y2;
	}
	
	int l = 0, r = 1e9 + 5;
	
	while(l + 1 < r){
		int mid = l + (r - l) / 2;
		if(getPasturesCount(pastures, mid) >= k){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	cout << r << endl;
	
	return 0;

}

