#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int s;
	while(cin >> s)
	{
		int num[s + 1][s + 1];
		for(int i = 0 ; i <= s ; i++)
			for(int j = 0 ; j <= s ; j++)
				num[i][j] = 0;
		for(int i = 1 ; i <= s ; i++)
		{
			for(int j = 1 ; j <= s ; j++)
			{
				cin >> num[i][j];
				num[i][j] += num[i][j - 1];
			}
		}
		int ans = 0;
		for(int l = 0 ; l <= s ; l++)
		{
			for(int r = l + 1 ; r <= s ; r++)
			{
				int sum = 0;
				for(int i = 1 ; i <= s ; i++)
				{
					int now = num[i][r] - num[i][l];
					sum = max(now, now + sum);
					ans = max(ans, sum);
				}
			}
		}
		cout << ans << endl;
	}
}