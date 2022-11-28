#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	int a;
	cin >> a;
	for(int j = 0 ; j < a ; ++j)
	{
		int n;
		cin >> n;
		int num[10] = {0};
		for(int i = 1 ; i <= n ; i++)
		{
			int x = i;
			while(x)
			{
				num[x % 10]++;
				x /= 10;
			}
		}
		for(int i = 0 ; i < 9 ; i++)
			cout << num[i] << " ";
		cout << num[9];
		cout << endl;
	}
}