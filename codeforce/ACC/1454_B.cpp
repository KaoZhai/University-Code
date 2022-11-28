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
		int a;
		cin >> a;
		int num[a+1] = {0}, max = -1;
		int cnt[MAX] = {0};
		for(int i = 1 ; i <= a ; i++)
		{
			cin >> num[i];
			if(num[i] > max)
				max = num[i];
			cnt[num[i]]++;
		}
		int ans = 0;
		for(int i = 1 ; i <= max ; i++)
		{
			if(cnt[i] == 1)
			{
				ans = i;
				break;
			}
		}
		if(ans)
		{
			for(int i = 1 ; i <= a ; i++)
			{
				if(ans == num[i])
				{
					ans = i;
					break;
				}
			}
			cout << ans << endl;
		}
		else
			cout << "-1" << endl;
	}
}