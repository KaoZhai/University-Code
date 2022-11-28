#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	bool flag = false;
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	if(s.length() == 1)
		cout << s << "\n";
	else
	{
		for(int i = 0 ; i < s.length() ; i += 2)
		{
			if(s[i] == '1')
				cnt1++;
			else if(s[i] == '2')
				cnt2++;
			else if(s[i] == '3')
				cnt3++;
		}
		while(cnt1--)
		{
			if(flag)
				cout << "+1";
			else
			{
				cout << "1";
				flag = true;
			}
		}
		while(cnt2--)
		{
			if(flag)
				cout << "+2";
			else
			{
				cout << "2";
				flag = true;
			}
		}
		while(cnt3--)
		{
			if(flag)
				cout << "+3";
			else
			{
				cout << "3";
				flag = true;
			}
		}
		cout << endl;
	}
}