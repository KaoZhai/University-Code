#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int64_t a, b, c;
	cin >> a >> b >> c;
	cout << ((a - 1) / c + 1) * ((b - 1) / c + 1) << endl;
}