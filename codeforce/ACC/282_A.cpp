#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	int ans = 0;
	while(t--)
	{
		string s;
		cin >> s;
		if(s[1] == '+' || s[2] == '+')
			ans++;
		else
			ans--;
	}
	cout << ans << "\n";
}