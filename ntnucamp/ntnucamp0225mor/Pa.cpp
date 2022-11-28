#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	string a;
	int ans[26] = {0}, point[26];
	for(int i = 0 ; i < 26 ; i++)
		point[i] = i;
	getline(cin,a);
	while(t--)
	{
		getline(cin,a);
		for(int i = 0 ; i < a.size() ; i++)
		{
			if(a[i] <= 'Z' && a[i] >= 'A')
				ans[a[i] - 'A']++;
			else if(a[i] <= 'z' && a[i] >= 'a')
				ans[a[i] - 'a']++;
		}
	}
	for(int i = 0 ; i < 26 ; i++)
			for(int j = i + 1 ; j < 26 ; j++)
				if(ans[i] < ans[j] || (ans[i] == ans[j] && point[i] > point[j]))
				{
					swap(ans[i],ans[j]);
					swap(point[i], point[j]);
				}
	for(int i = 0 ; i < 26 ; i++)
	{
		if(ans[i] == 0)
			break;
		printf("%c %d\n", point[i] + 'A', ans[i]);
	}
}