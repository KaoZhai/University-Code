#include <bits/stdc++.h>
#define MAXL 10010
#define MOD %1000000007
using namespace std;

int DP[MAXL] = {0};
int Pow[MAXL] = {0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	int num[MAXL] = {0};
	for(int i = 0 ; i < n ; i++)
		cin >> num[i];

	Pow[0] = 1;
	for(int i = 1 ; i < MAXL ; i++)
		Pow[i] = Pow[i - 1] * 2 MOD;

	int64_t ans = 0;
	for(int i = 1 ; i < n ; i++)
	{
		for(int j = 0 ; j < i ; j++)
		{
			if(abs(num[i] - num[j]) <= m)
				DP[i] = (DP[i] + Pow[j])MOD;
			else
				DP[i] = (DP[j] + DP[i])MOD;
		}
		ans = (ans + DP[i])MOD;
	}

	cout << ans << endl;
}
