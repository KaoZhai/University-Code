#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	cin >> a;
	if(a % 2 || a == 2)
		cout << "NO\n";
	else
		cout << "YES\n";
}