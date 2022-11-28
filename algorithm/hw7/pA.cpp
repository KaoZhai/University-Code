#include <bits/stdc++.h>
#define MAX_INT 2147483647

using namespace std;

int N, M, S, T, ans;
queue<int> pathu;
queue<int> pathv;
int cnt, minn = MAX_INT;
bool visit[110];
int mapp[110][110];

int search(int S, int T)
{
	//cout << "search " << S << " to " << T << endl;
	//cout << "in search" << endl;
	visit[S] = true;

	if(S == T)
		return 1;

	for(int i = 1 ; i <= N ; i++)
	{
		//cout << "S: " << S << " i: " << i << " mapp[S][i]: " << mapp[S][i] << endl;
		if(visit[i] == false && mapp[S][i] && search(i, T))
		{
			cnt++;
			pathu.push(S);
			pathv.push(i);
			return minn = min(mapp[S][i], minn);
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M >> S >> T;
	int u, v, w;

	for(int i = 0 ; i < M ; i++)
	{
		cin >> u >> v >> w;
		mapp[u][v] += w;
		mapp[v][u] = mapp[u][v];
	}
	int cur, curv, curu;

	while(cur = search(S, T))
	{
		for(int i = 0 ; i <= N ; i++)
			visit[i] = false;
		minn = MAX_INT;
		//cout << "cur: " << cur << " one path: \n"; 
		for(int i = 0 ; i < cnt ; i++)
		{
			curu = pathu.front();
			curv = pathv.front();
			//cout << "from " << curu << " to " << curv << "\n";
			pathu.pop();
			pathv.pop();
			mapp[curu][curv] -= cur;
			mapp[curv][curu] += cur;
		}
		ans += cur;
		cnt = 0;
	}
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