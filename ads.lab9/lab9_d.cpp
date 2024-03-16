#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector <int> prefix_function(string s){
	vector <int> pr(s.length());
	for (int i = 1; i < s.length(); i++){
		int j = pr[i - 1];
		while(j > 0 && s[i] != s[j]) j = pr[j - 1];
		if(s[i] == s[j]) j++;
		pr[i] == j;
	}
	return pr;
}

int longestPrefixSuffix(string s){
	int n = s.length();
	int lps[n];
	lps[0] = 0;
	int len = 0;
	int i = 1;
	
	while(i <n){
		if(s[i] == s[len]){
			len++;
			lps[i] = len;
			i++;
		}
		else if(s[i] != s[len]){
			if(len != 0){
				len = lps[len - 1];
			}
			else{
				lps[i] = 0;
				i++;
			}
		}
	}
	int res = lps[n - 1];
	if(res > n/2){
		res /= 2;
	}
	return res;
}

string tolower(string s){
	for(int i = 0; i < s.size(); i++){
		if(s[i] >= 65 && s[i] <= 92){
			s[i] = s[i] + 32;
		}
	}
	return s;
}

int main(){
	string text; cin >> text;
	int n; cin >> n;
	int max = -1;
	unordered_map <string, int> mapa;
	vector <string> ans_order;
	for(int i = 0; i < n; i++){
		string x;
		cin >> x;
		string allstr = tolower(x) + "#" + tolower(text);
		int ans = longestPrefixSuffix(allstr);
		if(ans >= max){
			if(ans == 0){
				continue;
			}
			max = ans;
			ans_order.push_back(x);
		}
		mapa[x] = ans;
	}
	int cnt = 0;
	
	for(int i = 0; i < ans_order.size(); i++){
		if(mapa[ans_order[i]] == max){
			cnt++;
		}
	}
	if(cnt == 0){
		cout << 0;
		return 0;
	}
	cout << cnt << endl;
	
	for(int i = 0; i < ans_order.size(); i++){
		if(mapa[ans_order[i]] == max){
			cout << ans_order[i] << endl;
		}
	}
	return 0;
}
