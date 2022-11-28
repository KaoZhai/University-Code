#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, k, ans = 0, cnt = 0, score = 0;
	cin >> t >> k;
	while(t--)
	{
		int num;
		cin >> num;
		if(score)
		{
			if(num >= score)
				ans++;
			continue;
		}
		if(num && cnt < k)
			cnt++;
		if(num && (!score) && cnt == k)
			score = num;
		if(num)
			ans++;
	}
	cout << ans << endl;
}