#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int DP[5][30010];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	cin >> a;
	int coins[5] = {0, 5, 10, 25, 50};
	for(int i = 0 ; i <= a ; i++)
		DP[0][i] = 1;
	for(int i = 1 ; i < 6 ; i++)
	{
		for(int j = 1 ; j <= a ; j++)
		{
			if(j - coins[i] >= 0)
				DP[i][j] = DP[i - 1][j] + DP[i][j - coins[i]];
			else
				DP[i][j] = DP[i - 1][j];
			// printf("i:%d j:%d DP:%d\n", i, j, DP[i][j]);
		}
	}

	if(DP[4][a] <= 1)
		printf("There is only 1 way to produce %d cents change.\n", a);
	else
		printf("There are %d ways to produce %d cents change.\n", DP[4][a], a);
}