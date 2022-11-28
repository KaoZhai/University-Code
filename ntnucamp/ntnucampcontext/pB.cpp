#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
	{
		int a, flag = 0, ans;
		cin >> a;
		for(int i = a - 50 ; i < a ; i++)
		{
			int tmp = i, sum = i;
			while(tmp > 0)
			{
				sum += tmp % 10;
				tmp /= 10;
			}
			if(sum == a)
			{
				flag = 1;
				ans = i;
				break;
			}
		}
		if(flag)
			cout << ans << endl;
		else
			cout << "0" << endl;
	}
}