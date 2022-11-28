#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
			break;
		int64_t DP[a + 1][b + 1] = {};
		for(int i = 0 ; i <= a ; i++)
		{
			for(int j = 0 ; j <= b ; j++)
			{
				if(!i)
					DP[i][j] = 1;
				else if(!j)
					DP[i][j] = 1;
				else if(i == j)
					DP[i][j] = 1;
			}
		}
		for(int i = 1 ; i <= a ; i++)
			for(int j = 1 ; j <= b ; j++)
			{
				if(i != j)
					DP[i][j] = DP[i - 1][j] + DP[i - 1][j - 1];
			}
		cout << a << " things taken " << b << " at a time is " << DP[a][b] << " exactly." << endl;
	}
}