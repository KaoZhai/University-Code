#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	string s;
	int high = 11, low = 0;
	while(cin >> a)
	{
		if(!a)
			break;
		getline(cin, s);
		getline(cin, s);
		if(s == "too high")
			high = min(a, high);
		else if(s == "too low")
			low = max(a, low);
		else
		{
			if(low == 0)
			{
				if(high == 11)
					cout << "Stan may be honest" << endl;
				else
				{
					if(a < high)
						cout << "Stan may be honest" << endl;
					else
						cout << "Stan is dishonest" << endl;
				}
			}
			else
			{
				if(high == 11)
				{
					if(a > low)
						cout << "Stan may be honest" << endl;
					else
						cout << "Stan is dishonest" << endl;
				}
				else
				{
					if(a < high && a > low)
						cout << "Stan may be honest" << endl;
					else
						cout << "Stan is dishonest" << endl;
				}
			}
			high = 11;
			low = 0;
		}
	}
}