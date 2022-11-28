#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	for(int i = 0 ; i < s.length() ; ++i)
	{
		if(s[i] != 'a' && s[i] != 'A' && s[i] != 'O' && s[i] != 'o' && s[i] != 'Y' && s[i] != 'y' && s[i] != 'E' && s[i] != 'e' && s[i] != 'U' && s[i] != 'u' && s[i] != 'i' && s[i] != 'I')
		{
			if(s[i] >= 'B' && s[i] <= 'Z')
				s[i] = tolower(s[i]);
			cout << "." << s[i];
		}
	}
	cout << endl;
}