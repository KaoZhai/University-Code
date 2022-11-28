#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;


int64_t col[10010];
	
int search(int64_t x, int l, int cur, int r)
{

	cout << "x = " << x << " col[cur] = " << col[cur] << endl;
	if(col[cur] == x)
		return 1;
	if(cur <= l || cur > r)
		return 0;
	if(x > col[cur])
	{
		l = cur;
		return search(x, l, (cur + r) / 2, r);
	}
	else
	{	
		r = cur;
		return search(x, l, (cur + l) / 2, r);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	for(int i = 1 ; i <= 10000 ; i++)
		col[i] = i * i * i;
	int t;
	cin >> t;
	while(t--)
	{
		int64_t num;
		cin >> num;
		int flag = 0;
		for(int64_t i = 1 ; i < 10000 ; i++)
		{
			if(i * i * i >= num)
				break;
			if(search(num - (i * i * i), 0, 5000, 10001))
			{
				flag = 1;
				break;
			}
		}
		if(flag == 1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}