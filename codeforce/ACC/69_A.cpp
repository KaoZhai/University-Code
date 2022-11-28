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
	int a = 0, b = 0, c = 0;
	while(t--)
	{
		int aa, bb, cc;
		cin >> aa >> bb >> cc;
		a += aa;
		b += bb;
		c += cc;
	}
	if(a || b || c)
		cout << "NO\n";
	else
		cout << "YES\n";
}