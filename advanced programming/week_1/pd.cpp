#include <bits/stdc++.h>
using namespace std;

int cnt(int a)
{
	int sum = a;
	while(a > 0)
	{
		sum += a % 10;
		a /= 10;
	}
	return sum;
}

int main()
{
	int a;
	cin >> a;
	for(int i = 0 ; i < a ; i++)
	{
		bool flag = false;
		int num;
		cin >> num;
		for(int j = num - 100 ; j <= num - 1 ; j++)
		{
			if(cnt(j) == num)
			{
				cout << j << endl;
				flag = true;
				break;
			}
		}
		if(!flag)
			cout << "0\n";
	}
}