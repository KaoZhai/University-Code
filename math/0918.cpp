#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double x = 0.0;
	double ans = 0.0;
	cout << "x= " << endl;
	cin >> x;
	ans = x;
	for(int i = 1 ; i < 50 ; i++)
	{
		ans += 1;
		ans *= x;
	}
	cout << ans + 1 << endl;
}