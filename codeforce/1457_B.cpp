#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
	{
		int n = 0, k = 0;
		cin >> n >> k;
		int num[n + 1];
		bool check[110] = {false};
		int cnt = 0;
		for(int i = 1 ; i <= n ; ++i)
		{
			cin >> num[i];
			check[num[i]] = true;
		}

		int min = INT_MAX;
		for(int i = 1 ; i <= 100; ++i)
		{
			if(check[i])
			{
				cnt = 0;
				for(int j = 1 ; j <= n ; j++)
				{
					if(num[j] != i)
					{
						cnt++;
						j += (k - 1);
					}
				}
				if(cnt < min)
					min = cnt;
			}
		}
		cout << min << endl;
	}
}