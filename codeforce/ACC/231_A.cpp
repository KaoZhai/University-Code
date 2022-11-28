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
		int a, b, c;
		cin >> a >> b >> c;
		if(a + b + c >= 2)
			ans++;
	}
	cout << ans << endl;
}