#include <bits/stdc++.h>
#define MAX 3010
using namespace std;

int mapp[MAX][MAX] = {0};
bool visit[MAX] = {0};
int N = 0;

int dfs(int a, int b)
{
	int tmp = 0;
	visit[a] = 1;
	if(a == b)
		return 2147483647;
	int cnt = 0;
	for(int i = 1 ; i < MAX && cnt < N ; i++)
	{
		if(mapp[a][i] != 0)
			cnt++;
		if(mapp[a][i] != 0 && visit[i] == 0)
		{
			tmp = dfs(i, b);
			if(tmp)
				return min(tmp, mapp[a][i]);
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	int is1, is2, weight;
	for(int i = 1 ; i < N ; i++)
	{
		cin >> is2 >> is1 >> weight;
		mapp[is1][is2] = weight;
		mapp[is2][is1] = weight;
	}
	int sta, fin;
	cin >> sta >> fin;
	cout << dfs(sta, fin) << endl;
}