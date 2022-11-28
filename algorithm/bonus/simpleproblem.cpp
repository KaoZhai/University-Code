#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int64_t n, m;
	cin >> n >> m;
	int64_t total = ((int64_t)n * (int64_t)(n - 1)) / 2;
	int64_t pre = n;
	for(int64_t i = n - 1 ; i >= 0 ; i--)
	{
		if(total - i >= m)
		{
			cout << n - i << " ";
			if(i != pre - 1)
			{
				for(int64_t j = n ; j > n - i ; j--)
					cout << j << " ";
				for(int64_t j = n - i - 1 ; j > n - pre ; j--)
					cout << j << " ";
				cout << endl;
				break;
			}
			pre = i;
			total -= i;
		}
		if(total == m)
		{
			for(int64_t j = 0 ; j < pre ; j++)
				cout << n - j << " ";
			cout << endl;
			break;
		}
	}
}