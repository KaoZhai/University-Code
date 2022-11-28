#include <bits/stdc++.h>

using namespace std;

typedef struct _num{
	int place;
	int number;
}num;

bool cmp(num a, num b)
{
	return a.number < b.number;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t, innum;
	while(cin >> t)
	{
		int max = 0;
		num input[t];
		for(int i = 0 ; i < t ; i++)
		{
			cin >> innum;
			input[i].place = i;
			input[i].number = innum;
		}
		sort(input, input + t, cmp);
		for(int i = 0 ; i < t ; i++)
		{
			if(input[i].place - i > max)
				max = input[i].place - i;
		}
		cout << max << endl;
	}
}