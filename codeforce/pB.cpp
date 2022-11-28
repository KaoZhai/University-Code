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
		int64_t n, k;
		cin >> n >> k;
		int64_t ans = 0;
		int64_t num[n];
		for(int i = 0 ; i < n ; i++)
			cin >> num[i];
		int64_t sum = 0;
		sum = num[0];
		for(int i = 1 ; i < n ; i++)
		{
			// cout << "i = " << i <<" num[i] = " << num[i] << " sum = " << sum << endl; 
			int64_t tmp = 0;
			if(num[i] * 100 - k * sum > 0)
			{
				tmp = (num[i] * 100 - k * sum) / k;
				if((num[i] * 100 - k * sum) % k)
					tmp++;
			}
			// cout << "i = " << i << " tmp = " << tmp << endl;
			ans += tmp;
			sum += tmp + num[i];
		}

		cout << ans << endl;
	}
}