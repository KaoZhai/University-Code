#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int64_t t;
	cin >> t;
	while(t--)
	{
		int64_t n, k, tmp = 0;
		cin >> n >> k;
		tmp = k;
		while(tmp < n)
			tmp += k;
		if(tmp % n)
			cout << tmp / n + 1;
		else
			cout << tmp / n;
		cout << endl;
	}
}