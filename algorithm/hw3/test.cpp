#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int num[4];
	int ans = 0;

	for(int i = 0 ; i < 4 ; i++)
		cin >> num[i];

	for(int i = 0 ; i < 3 ; i++)
		for(int j = i + 1 ; j < 4 ; j++)
			if(abs(num[j] - num[i]) <= 2)
				ans++;

	if(abs(num[1] - num[0]) <= 2 || abs(num[1] - num[2]) <= 2)
		ans++;
	if(abs(num[1] - num[0]) <= 2 || abs(num[1] - num[3]) <= 2)
		ans++;
	if(abs(num[2] - num[0]) <= 2 || abs(num[3] - num[2]) <= 2)
		ans++;
	if(abs(num[1] - num[2]) <= 2 || abs(num[3] - num[2]) <= 2)
		ans++;
	if(abs(num[1] - num[0]) <= 2 || abs(num[1] - num[2]) <= 2 || abs(num[2] - num[3]) <= 2)
		ans++;

	cout << ans << endl;
}