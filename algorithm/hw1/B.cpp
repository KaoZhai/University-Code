#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int64_t n, d;
	while(cin >> n >> d)
	{
		int64_t num[n], cnt = 0, sum = 0, ch = 0, tmp;
		for(int64_t i = 0 ; i < n ; i++)
		{
			cin >> num[i];
			sum += num[i];
			if(sum == d)
			{
				ch = 1;
				tmp = i;
				break;
			}
			else if(sum > d)
			{
				while(sum > d && cnt < i)
					sum -= num[cnt++];
				if(sum == d)
				{
					ch = 1;
					tmp = i;
					break;
				}
			}
		}
		tmp = n - tmp - 1;
		while(tmp--)
			cin >> sum;
		if(ch)
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
}