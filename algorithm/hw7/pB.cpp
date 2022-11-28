#include <bits/stdc++.h>
#define MAX_INT 2147483647

using namespace std;

int N, M, S, T, ans;
queue<int> node;
int cnt, minn = MAX_INT;
bool visit[310];
int mapp[310][310];

int bfs()
{
	visit[S] = true;
	node.push(S);
	while(!node.empty())
	{
		int tem = node.front();
		node.pop();
		for(int i = 1 ; i <= T ; i++)
		{
			if(mapp[tem][i] && visit[i] == false)
			{
				
			}
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	S = N + 1;
	T = N + 2;
	int u, v, w;

	for(int i = 1 ; i <= N ; i++)
	{
		cin >> w;
		mapp[S][i] = w;
	}
	for(int i = 1 ; i <= N ; i++)
	{
		cin >> w;
		mapp[i][T] = w;
	}
	for(int i = 0 ; i < M ; i++)
	{
		cin >> u >> v >> w;
		mapp[u][v] += w;
		mapp[v][u] = mapp[u][v];
	}

	bfs();
	//cout << "cur " << cur << endl;
	//cout << "mapp" << endl;
	// for(int i = 1 ; i <= N ; i++)
	// {
	// 	for(int j = 1 ; j <= N ;j++)
	// 		cout << mapp[i][j] << " ";
	// 	cout << endl;
	// }

	cout << ans << endl;
	return 0;
}