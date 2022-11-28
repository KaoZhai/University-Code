#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string a;
	map<int, int> data;
	int id, q;
	while(1)
	{
		cin >> a;
		if(a[0] == '#')
			break;
		cin >> id >> q;
		data[id] = q;
	}
	int test, cnt = 0;
	queue<int> ans;
	cin >> test;
	for(int i = 1 ; ; i++)
	{
		for(map<int, int>::iterator j = data.begin() ; j != data.end() ; j++)
		{
			if(!(i % j -> second))
			{
				ans.push(j -> first);
				cnt++;
			}
			if(cnt == test)
				break;
		}
		if(cnt == test)
			break;
	}
	for(int i = 0 ; i < test ; i++)
	{
		cout << ans.front() << endl;
		ans.pop();
	}
}