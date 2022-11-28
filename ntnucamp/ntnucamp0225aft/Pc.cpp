#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while(1)
	{
		int a;
		cin >> a;
		if(a == 0)
			break;
		while(1)
		{
			int num[a], cnt = 0, flag = 1;
			stack<int> st;
			for(int i = 0 ; i < a ; i++)
			{
				cin >> num[i];
				if(num[i] == 0)
				{
					flag = 0;
					cout << endl;
					break;
				}
			}
			if(!flag)
				break;
			for(int i = 1 ; i <= a ; i++)
			{
				st.push(i);
				while(num[cnt] == st.top())
				{
					st.pop();
					cnt++;
					if(st.empty())
						break;
				}
			}
			if(st.empty())
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
}