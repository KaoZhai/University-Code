#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 100010
using namespace std;

int n;
int64_t num;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	int64_t sum = 0, max = -1;
	int64_t want;
	while(t--)
	{
		cin >> n;
		sum = 0;
		max = -1;
		for(int i = 1 ; i <= n ; ++i)
		{
			cin >> num;
			if(num > max)
				max = num;
			sum += num;
		}
		want = max * (n - 1);
		if(want < sum)
			want += (n - 1) * ((sum - want) / (n - 1));
		if(want < sum)
			want += (n - 1);
		cout << want - sum << "\n";
	}
}