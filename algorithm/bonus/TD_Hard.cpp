#include <bits/stdc++.h>

using namespace std;

#define MAXL 3010

int mapp[MAXL][MAXL];
int disjoint[MAXL];
bool visit[MAXL] = {0};
int N, M;

typedef struct _edge{
	int v, u, w;
}edge;

bool cmp(edge a, edge b)
{
	return a.w > b.w;
}

void init(int n)
{
	for(int i = 0 ; i <= n ; i++)
		disjoint[i] = i;
	return;
}

int find(int n)
{
	if(disjoint[n] == n)
		return n;
	return find(disjoint[n]);
}

void Union(int a, int b)
{
	int fa = find(a), fb = find(b);
	disjoint[fa] = fb;
	return;
}

int dfs(int a, int b)
{
	int tmp;
	visit[a] = 1;
	if(a == b)
		return 2147483647;
	for(int i = 1 ; i <= N ; i++)
	{
		if(mapp[a][i] && visit[i] == 0)
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

	cin >> N >> M;

	edge line[M];
	init(N);

	for(int i = 0 ; i < M ; i++)
		cin >> line[i].v >> line[i].u >> line[i].w;

	int start, final;
	cin >> start >> final;

	sort(line, line + M, cmp);

	for(int i = 0 ; i < M ; i++)
	{
		if(find(line[i].u) != find(line[i].v))
		{
			Union(line[i].u, line[i].v);
			mapp[line[i].u][line[i].v] = mapp[line[i].v][line[i].u] = line[i].w;
		}
	}

	// for(int i = 1 ; i <= N ; i++)
	// {
	// 	for(int j = 1 ; j <= N ; j++)
	// 		cout << mapp[i][j] << " ";
	// 	cout << endl;
	// }

	cout << dfs(start, final) << endl;
}