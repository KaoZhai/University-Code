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
		int num[n+1], ans = 0;
		for(int i = 1 ; i <= n ; i++)
		{
			cin >> num[i];
			if(i > 1)
			{
				int tmp = num[i - 1];
				if(num[i] > num[i - 1])
				{
					int check = num[i] % 2;
					while(tmp < num[i] / 2 || (tmp == num[i] / 2 && check))
					{
						// cout << "tmp = " << tmp << endl;
						tmp *= 2;
						ans++;
					}
				}
				else if(num[i] < num[i - 1])
				{
					while(tmp > num[i] * 2)
					{
						// cout << "tmp = " << tmp << endl;
						if(tmp % 2)
							tmp = tmp / 2 + 1;
						else
							tmp /= 2;
						ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}
}