#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		if(s.length() <= 10)
			cout << s << "\n";
		else
			cout << s[0] << s.length() - 2 << s[s.length() - 1] << "\n";
	}
}