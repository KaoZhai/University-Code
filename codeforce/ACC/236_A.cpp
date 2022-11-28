#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	bool check[26] = {false};
	int cnt = 0;
	for(int i = 0 ; i < s.length() ; ++i)
	{
		if(!check[s[i] - 97])
		{
			check[s[i] - 97] = true;
			cnt++;
		}
	}
	if(cnt % 2 == 0)
		cout << "CHAT WITH HER!\n";
	else
		cout << "IGNORE HIM!\n";
}