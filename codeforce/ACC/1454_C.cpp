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
		int n;
		int cnt[MAX] = {0};
		bool flag[MAX] = {false};
		cin >> n;
		int num[n+1] = {0};
		cin >> num[1];
		flag[num[1]] = true;
		for(int i = 2 ; i <= n ; i++)
		{
			cin >> num[i];
			flag[num[i]] = true;
			if(num[i] != num[i - 1])
			{
				cnt[num[i]]++;
			}
		}
		cnt[num[n]]--;
		for(int i = 1 ; i <= n ; i++)
			cnt[i]++;
		int min = INT_MAX;
		for(int i = 1 ; i <= n ; i++)
			if(min > cnt[i] && flag[i])
			{
				min = cnt[i];
			}
		cout << min << endl;
	}
}