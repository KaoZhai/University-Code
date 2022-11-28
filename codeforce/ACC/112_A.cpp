#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a, b;
	cin >> a >> b;
	for(int i = 0 ; i < a.length() ; ++i)
	{
		a[i] = tolower(a[i]);
		b[i] = tolower(b[i]);
		if(a[i] > b[i])
		{
			cout << "1\n";
			return 0;
		}
		else if(a[i] < b[i])
		{
			cout << "-1\n";
			return 0;
		}
	}
	cout << "0\n";
}