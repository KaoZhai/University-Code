#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010
using namespace std;

int64_t cnt[MAX] = {0}, coe[MAX] = {0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
	{
		int64_t num, tmp;
		cin >> num;
		tmp = num;
		for(int i = 0 ; i < MAX ; i++)
		{
			cnt[i] = 0;
			coe[i] = 0;
		}
		int64_t flag = 0;
		for(int64_t i = 2 ; i <= sqrt(tmp) + 1 || (num > 1 && num < 4) ; i++)
		{
			if(num % i == 0 || num == i)
			{
				flag++;
				coe[flag] = i;
				while(num % i == 0 || num == i)
				{
					num /= i;
					cnt[flag]++;
				}
			}
			if(num == 1)
				break;
		}
		for(int i = 1 ; i <= flag ; ++i)
			for(int j = i + 1 ; j <= flag ; ++j)
				if(cnt[j] > cnt[i])
				{
					swap(cnt[i], cnt[j]);
					swap(coe[i], coe[j]);
				}
		int64_t cntt = cnt[1];
		if(cntt == 0)
		{
			cout << "1" << endl << num << endl;
			continue;
		}
		cout << cntt << endl;
		for(int i = 1 ; i <= cntt ; i++)
		{
			int64_t ans = 1;
			if(i == cntt)
			{
				for(int j = 1 ; j <= flag ; ++j)
				{
					for(int k = 0 ; k < cnt[j] ; k++)
						ans *= coe[j];
				}
				ans *= num;
				cout << ans << endl;
			}
			else
			{
				for(int j = 1 ; j <= i ; ++j)
				{
					if(coe[j] && cntt - i < cnt[j])
					{
						ans *= coe[j];
						cnt[j]--;
					}
				}
				cout << ans << " ";
			}
		}
	}
}