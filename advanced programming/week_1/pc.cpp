#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a;
	bool cheat = false;

	int max = 11, min = 0;
	while(cin >> a)
	{
		if(a == 0)
			break;
		string strr, str;
		cin >> strr >> str;
		if(str[1] == 'i')
		{
			if(a < max)
				max = a;
			if(a <= min + 1)
				cheat = true;
		}
		else if(str[1] == 'o')
		{
			if(a > min)
				min = a;
			if(a >= max - 1)
				cheat = true;
		}
		else
		{
			if(a <= min || a >= max)
				cheat = true;
			if(cheat)
				cout << "Stan is dishonest" << endl;
			else
				cout << "Stan may be honest" << endl;
			max = 11;
			min = 0;
			cheat = false;
		}
	}
}