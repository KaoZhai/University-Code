#include <bits/stdc++.h>
#define MAXL 10010
using namespace std;

int DP[MAXL][MAXL] = {0};
int Sum[MAXL] = {0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, K;
	cin >> N >> K;
	int number[N/K] = {0};
	for(int i = 0 ; i < N/K ; i++)
	{
		int num, tmp = 0;
		for(int j = 0 ; j < K ; j++)
		{
			cin >> num;
			tmp += num;
		}
		number[i] = tmp;
	}
	Sum[0] = number[0];
	for(int i = 1 ; i < N/K ; i++)
		Sum[i] = Sum[i - 1] + number[i];

	for(int i = N/K - 1 ; i >= 0 ; i--)
	{
		for(int j = i ; j < N/K ; j++)
		{
			if(j == i)
			{
				DP[i][j] = number[i];
			}
			else
			{
				DP[i][j] = Sum[j] - Sum[i - 1] - min(DP[i + 1][j], DP[i][j - 1]);
			}
		}
	}

	// for(int i = 0 ; i < N/K ; i++)
	// {
	// 	for(int j = 0 ; j < N/K ; j++)
	// 		cout << DP[i][j] << " ";
	// 	cout << endl;
	// }
	// cout << endl;

	int ans1, ans2;
	ans1 = DP[0][N/K - 1];
	ans2 = Sum[N/K - 1] - ans1;

	if(ans1 > ans2)
		cout << ans1 << " " << ans2;
	else
		cout << ans2 << " " << ans1;

	return 0;
}