#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	map<string,string> nickname;
	map<string,string> owner;
	while(n--)
	{
		string a,b;
		cin>>a>>b;
		if(owner.find(a) == owner.end())
		{
			nickname[a]=b;
			owner[b]=a;
		}
		else
		{
			string own = owner[a];
			nickname[own]=b;
			owner[b]=own;

		}

	}
	cout<<nickname.size()<<endl;
	for(map<string,string>::iterator it=nickname.begin(); it!=nickname.end(); it++)
	{
		cout<<it->first<<" "<<it->second<<endl;
	}

	return 0;
}
