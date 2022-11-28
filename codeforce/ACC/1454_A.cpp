#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
	{
		int a;
		cin >> a;
		for(int i = 1 ; i < a ; i++)
			cout << i + 1 << " ";
		cout << "1\n";
	}
}