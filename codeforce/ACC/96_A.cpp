#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	bool dan = false;
	int cnt = 0;
	cin >> s;
	for(int i = 1 ; i < s.length() ; i++)
	{
		if(s[i] == s[i - 1])
			cnt++;
		else
			cnt = 0;
		if(cnt == 6)
		{
			dan = true;
			break;
		}
	}
	if(dan)
		cout << "YES\n";
	else
		cout << "NO\n";
}