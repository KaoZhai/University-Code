#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a;
	while(cin >> a)
	{
		list<char> ans;
		list<char>::iterator it = ans.begin();
		for(int i = 0 ; i < a.size() ; i++)
		{
			if(a[i] != '[' && a[i] != ']')
				ans.insert(it, a[i]);
			else if(a[i] == '[')
				it = ans.begin();
			else if(a[i] == ']')
				it = ans.end();
		}
		for(list<char>::iterator i = ans.begin() ; i != ans.end() ; i++)
			cout << *i;
		cout << endl;
	}
}