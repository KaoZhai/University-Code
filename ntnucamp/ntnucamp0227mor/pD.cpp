#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a, b;
	while(getline(cin,a))
	{
		getline(cin,b);
		int as = a.size(), bs = b.size() ;
		int DP[as + 1][bs + 1] = {};
		for(int i = 0 ; i < as ; i++)
		{
			for(int j = 0 ; j < bs ; j++)
			{
				if(a[i] == b[j])
					DP[i + 1][j + 1] = DP[i][j] + 1;
				else
					DP[i + 1][j + 1] = max(DP[i][j + 1], DP[i + 1][j]);
			}
		}
		cout << DP[as][bs] << endl;
	}
}