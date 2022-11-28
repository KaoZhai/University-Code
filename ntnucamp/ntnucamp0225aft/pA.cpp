#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	string a, name;
	getline(cin, a);
	map<string, int> cnt;
	while(t--)
	{
		getline(cin, a);
		int flag = 0;
		for(int i = 0 ; i < a.size() ; i++)
		{
			if(a[i] == ' ')
				break;
			flag++;
		}
		name = a.substr(0, flag);
		cnt[name]++;
	}
	for(map<string, int>::iterator i = cnt.begin() ; i != cnt.end() ; i++)
		cout << i -> first << " " << i -> second << endl;
}