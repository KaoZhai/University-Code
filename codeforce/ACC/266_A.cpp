#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	string s;
	cin >> t;
	cin >> s;
	int ans = 0;
	for(int i = 1 ; i < t ; i++)
		if(s[i] == s[i - 1])
			ans++;
	cout << ans << "\n";
}