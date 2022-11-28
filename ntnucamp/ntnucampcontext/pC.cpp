#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	string a;
	map<string, int> ans;
	getline(cin,a);
	while(t--)
	{
		string name;
		int cnt = 0;
		getline(cin,a);
		for(int i = 0 ; i < a.size() ; i++)
		{
			if(a[i] != ' ')
				cnt++;
			else
				break;
		}
		name = a.substr(0, cnt);
		ans[name]++;
	}
	for(map<string, int>::iterator i = ans.begin() ; i != ans.end() ; i++)
	{
		cout << i -> first << " " << i -> second << endl;
	}
}