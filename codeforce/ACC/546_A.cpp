#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int64_t k, n, w;
	cin >> k >> n >> w;
	if(k * (1 + w) * w / 2 - n > 0)
		cout << k * (1 + w) * w / 2 - n << "\n";
	else
		cout << "0\n";
}