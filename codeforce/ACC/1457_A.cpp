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
		int64_t r, n, c, m;
		cin >> n >> m >> r >> c;
		cout << max(n - r, r - 1) + max(m - c, c - 1) << endl;
	}
}