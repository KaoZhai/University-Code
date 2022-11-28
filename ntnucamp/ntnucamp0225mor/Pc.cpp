#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	while(cin >> a)
	{
		int num[a], ans = 0;
		for(int i = 0 ; i < a ; i++)
			cin >> num[i];
		for(int i = 0 ; i < a ; i++)
			for(int j = 1 ; j < a ; j++)
				if(num[j] < num[j - 1])
				{
					ans++;
					swap(num[j], num[j - 1]);
				}
			cout << "Minimum exchange operations : " << ans << endl;
	}
}