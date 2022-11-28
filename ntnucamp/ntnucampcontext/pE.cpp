#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x, y;
	string a, b;
	while(cin >> x)
	{
		cin >> a >> y >> b;
		int DP[x + 1][y + 1] = {};
		for(int i = 1 ; i <= x ; i++)
		{
			for(int j = 1 ; j <= y ; j++)
			{
				if(a[i - 1] == b[j - 1])
					DP[i][j] = DP[i - 1][j - 1] + 1;
				else
					DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
		cout << y - DP[x][y] << endl;
	}
}