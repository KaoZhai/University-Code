#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	int t;
	int small = 0, big = 0, ans = 0;
	cin >> t;
	while(t--)
	{
		small = 0;
		big = 0;
		ans = 0;
		cin >> s;
		for(int i = 0 ; i < s.length() ; i++)
		{
			if(s[i] == '(')
				++small;
			else if(s[i] == '[')
				++big;
			else if(s[i] == ')' && small)
			{
				--small;
				++ans;
			}
			else if(s[i] == ']' && big)
			{
				--big;
				++ans;
			}
		}
		cout << ans << "\n";
	}
}