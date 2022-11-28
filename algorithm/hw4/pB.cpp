#include <bits/stdc++.h>

#define MAX 100010

using namespace std;

typedef struct _team{
	int l;
	int r;
}team;

team data[MAX];
vector<int> fire;

bool cmp(team a, team b)
{
	if(a.r != b.r)	return a.r < b.r;
	return a.l < b.l;
}

int main()
{
	int t;
	cin >> t;

	for(int i = 1 ; i <= t ; i++)
		cin >> data[i].l >> data[i].r;

	sort(&data[1], &data[t + 1], cmp);

	// for(int i = 1 ; i <= t ; i++)
	// 	cout << data[i].l << " " << data[i].r << endl;

	int ans = 0;
	for(int i = 1 ; i <= t ; i++)
	{
		int ch = 0;
		if(!fire.empty())
		{
			for(int j = fire.size() - 1 ; j >= 0 ; j--)
			{
				//cout << "i = " << i << " j = " << j << " l r : " << data[i].l << " " << data[i].r << " fire[j] : " << fire[j] << endl;
				if(fire[j] <= data[i].r && fire[j] >= data[i].l)
					ch++;
				if(ch == 2 || fire[j] < data[i].l)
					break;
			}
		}
		if(ch == 0)
		{
			ans += 2;
			fire.push_back(data[i].r - 1);
			fire.push_back(data[i].r);
		}
		else if(ch == 1)
		{
			ans++;
			if(fire.back() == data[i].r)
				fire[fire.size() - 1] = data[i].r - 1;
			fire.push_back(data[i].r);
		}
		// cout << "fire :";
		// for(int i = 0 ; i < fire.size() ; i++)
		// 	cout << " " << fire[i];
		// cout << endl;
	}
	cout << ans << endl;
}