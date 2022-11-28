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
		int n;
		cin >> n;
		int c[3] = {0,0,0}, num;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> num;
			c[(num % 3)]++;
		}
		int ans = 0, tmp = 0;
		tmp = n / 3;
		for(int i = 0 ; i < 6 ; i ++)
		{
			if(c[i % 3] > tmp)
			{
				ans += c[i % 3] - tmp;
				c[(i + 1) % 3] += c[i % 3] - tmp;
				c[i % 3] = tmp;
			}
		}
		cout << ans << endl;
	}
}