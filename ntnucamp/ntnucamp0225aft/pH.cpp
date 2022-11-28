#include <bits/stdc++.h>
using namespace std;

int uni[10000001];

void init(int x)
{
	for(int i = 1 ; i <= x ; i++)
		uni[i] = i;
}
int find(int x)
{
	if(x == uni[x])
		return x;
	return uni[x] = find(uni[x]);
}
void Union(int x, int y)
{
	int a = find(x);
	int b = find(y);
	if(a != b)
		uni[a] = b;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int a, no = 0, yes = 0;
		cin >> a;
		init(a);
		while(1)
		{
			char c;
			scanf("%c", &c);
			scanf("%c", &c);
			if(c != '\n')
			{
				if(c == 'c')
				{
					int num1, num2;
					cin >> num1 >> num2;
					Union(num1, num2);
				}
				else if(c == 'q')
				{
					int num1, num2;
					cin >> num1 >> num2;
					if(find(num1) != find(num2))
						no++;
					else
						yes++;
				}
			}
			else
			{
				cout << yes << "," << no << endl ;
				break;
			}
		}
		if(t)
			cout << "\n";
	}
}