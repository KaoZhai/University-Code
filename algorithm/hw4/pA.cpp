#include <bits/stdc++.h>
#define MAXL 100010
using namespace std;

typedef struct _node{
	int visit = 0;
	vector<int> con;
}node;

node input[MAXL];

void che(int a, int b)
{
	int ch = 0;
	for(int i = 0 ; i < input[a].con.size() ; i++)
		if(input[a].con[i] == b)
		{
			ch = 1;  
			break;
		}
	if(!ch)
	{
		input[a].con.push_back(b);
		input[b].con.push_back(a);
	}
	return;
}

void dfs(int index)
{
	if(input[index].visit == 1)
		return;
	cout << index << " ";
	input[index].visit = 1;
	for(int i = input[index].con.size() - 1 ; i >= 0 ; i--)
	{
		dfs(input[index].con[i]);
	}
	return;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;

	int a, b;
	for(int i = 0 ; i < t - 1 ; i++)
	{
		cin >> a >> b;
		che(a, b);
	}
	for(int i = 1 ; i <= t ; i++)
		sort(input[i].con.begin(), input[i].con.end());
	dfs(t);
	cout << endl;
}