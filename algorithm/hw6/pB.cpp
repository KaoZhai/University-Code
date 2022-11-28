#include <bits/stdc++.h>

using namespace std;

#define MAX 100010

int N, M, H, S1, S2, C;
bool visit[MAX];
int64_t dis[MAX];

typedef struct _loc{
	int beside;
	int64_t w;
}loc;

bool operator<(loc a, loc b)
{
	return a.w > b.w;
}

vector<loc> mapp[MAX];

void init(int home)
{
	for(int i = 1 ; i <= N ; i++)
	{
		dis[i] = 5000000000000;
		visit[i] = 0;
	}
	dis[home] = 0;
	return;
}

void dij(int start)
{
	init(start);

	priority_queue<loc> que;
	que.push({start, dis[start]});

	int64_t cur;
	for(int i = 1 ; i <= N ; i++)
	{
		// cout << "i = " << i <<  " dis[] : " ;
		// for(int j = 1 ; j <= N ; j++)
		// 	cout << dis[j] << " ";
		// cout << endl;

		cur = 0;
		while(!que.empty() && visit[cur = que.top().beside])
			que.pop();

		if(!cur)
			break;
		visit[cur] = 1;

		for(int j = 0 ; j < mapp[cur].size() ; j++)
		{
			int we = mapp[cur][j].w, b = mapp[cur][j].beside;
			if(!visit[b] && dis[cur] + we < dis[b])
			{
				dis[b] = dis[cur] + we;
				que.push({b, dis[b]});
			}
		}
	}
	while(!que.empty())
		que.pop();
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int64_t ans = 0;

	cin >> N >> M >> H >> S1 >> S2 >> C;

	int node1, node2;
	int64_t weight;
	for(int i = 0 ; i < M ; i++)
	{
		cin >> node1 >> node2 >> weight;
		mapp[node1].push_back({node2, weight});
		mapp[node2].push_back({node1, weight});
	}

	dij(H);
	ans += dis[S1];
	ans += dis[C];
	dij(S2);
	ans += dis[C];
	ans += dis[S1];

	cout << ans << endl;
}