#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MAX 200010

using namespace std;

vector<int> tree[MAX];
bool visit[MAX];
bool incircle[MAX];
int cnt[MAX] = {0};
int the_point = 0;

void init_visit(int n)
{
	for(int i = 0 ; i <= n ; ++i)
		visit[i] = false;
	return;
}

void init_tree(int n)
{
	for(int i = 0 ; i <= n ; ++i)
		tree[i].clear();
	return;
}

void init_cnt(int n)
{
	for(int i = 0 ; i <= n ; ++i)
		cnt[i] = 0;
	return;
}

void init_incircle(int n)
{
	for(int i = 0 ; i <= n ; ++i)
		incircle[i] = false;
	return;
}

int dfs_make_circle(int n, int pre)
{
	visit[n] = true;

	for(int i = 0 ; i < tree[n].size() ; i++)
	{
		if(visit[tree[n][i]] && tree[n][i] != pre)
		{
			the_point = tree[n][i];
			incircle[n] = true;
			return the_point;
		}
		else if(!visit[tree[n][i]])
		{
			if(dfs_make_circle(tree[n][i], n))
			{
				incircle[n] = true;
				if(n == the_point)
					the_point = 0;
				return the_point;
			}
		}
	}
	return 0;
}

int64_t dfs_count(int n)
{
	visit[n] = true;

	int64_t value = 1;
	for(int i = 0 ; i < tree[n].size() ; ++i)
	{
		if((!visit[tree[n][i]]) && (!incircle[tree[n][i]]))
			value += dfs_count(tree[n][i]);
	}
	return value;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while(t--)
	{
		int n, u, v;
		cin >> n;

		init_visit(n + 1);
		init_tree(n + 1);
		init_cnt(n + 1);
		init_incircle(n + 1);
		the_point = 0;
		int64_t ans = 0;
		ans = (int64_t)n * ((int64_t)n - 1);

		for(int i = 0 ; i < n ; ++i)
		{
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
			cnt[u]++;
			cnt[v]++;
		}

		dfs_make_circle(1, 0);

		init_visit(n);

		for(int i = 1 ; i <= n ; ++i)
		{
			if(cnt[i] >= 3 && incircle[i] && (!visit[i]))
			{
				int64_t more;
				more = dfs_count(i);
				ans -= (more - 1) * more / 2;
			}
		}

		cout << ans << endl;
	}
}