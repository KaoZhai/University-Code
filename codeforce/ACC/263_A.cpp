#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int num[6][6], ans = 0;
	for(int i = 1 ; i <= 5 ; i++)
		for(int j = 1 ; j <= 5 ; j++)
		{
			cin >> num[i][j];
			if(num[i][j])
				ans = abs(i - 3) + abs(j - 3);
		}
	cout << ans << "\n";
}