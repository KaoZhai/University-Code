#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	if(s[0] >= 'a' && s[0] <= 'z')
		s[0] = toupper(s[0]);
	cout << s << "\n";
}