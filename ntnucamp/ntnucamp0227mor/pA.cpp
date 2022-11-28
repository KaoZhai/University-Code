#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	while(cin >> a)
	{
		if(a == 0)
			break;
		int64_t DP[100010] = {0};
		DP[0] = 1;
		int coin[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
		for(int i = 0 ; i < 9 ; i++)
		{
			for(int j = 1 ; j <= a ; j++)
			{
				if(j - coin[i] >= 0)
					DP[j] += DP[j - coin[i]];
			}
		}
		cout << DP[a] << " possible" << endl;
	}
}