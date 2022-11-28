#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, a, b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		if(a == b)
			cout << 2 * a << "\n";
		else
			cout << 2 * max(a, b) - 1 << "\n"; 
	}
}