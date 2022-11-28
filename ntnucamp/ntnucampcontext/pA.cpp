#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
			break;
		int carda[max(a, b)] = {}, cardb[max(a, b)] = {}, cnta = 0, cntb = 0, num;
		int ch = 0;
		for(int i = 0 ; i < a ; i++)
		{
			cin >> num;
			if(!i)
				carda[cnta++] = num;
			else
			{
				if(carda[cnta - 1] != num)
					carda[cnta++] = num;
			}
		}
		for(int i = 0 ; i < b ; i++)
		{
			cin >> num;
			if(!i)
				cardb[cntb++] = num;
			else
			{
				if(cardb[cntb - 1] != num)
					cardb[cntb++] = num;
			}
		}
		for(int i = 0 ; i < cnta ; i++)
		{
			for(int j = 0 ; j < cntb ; j++)
			{
				if(carda[i] == cardb[j])
				{
					ch++;
					break;
				}
			}
		}
		cout << min(cnta, cntb) - ch << endl;
	}
}