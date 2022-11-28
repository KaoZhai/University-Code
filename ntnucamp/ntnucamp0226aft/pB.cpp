#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	while(1)
	{
		int n, m, u, v;
		cin >> n >> m;
		if(n == 0 && m == 0)
			return 0;
		bool G[110][110] = {false};
		int in[110] {};
		for(int i = 0 ; i < m ; i++)
		{
			cin >> u >> v;
			G[u][v] = true;
			in[v]++;
		}
		queue<int> q;
		for(int i = 1 ; i <= n ; i++)
		{
			if(!in[i])
				q.push(i);
		}
		vector<int> ans;
		while(!q.empty())
		{
			int t = q.front();
			ans.push_back(t);
			q.pop();

			for(int i = 1 ; i <= n ; i++)
			{
				if(G[t][i])
				{
					in[i]--;
					if(!in[i])
						q.push(i);
				}
			}
		}
		for(int i = 0 ; i < (int)ans.size() ; i++)
		{
			if(i < (int)ans.size() - 1)
				cout << ans[i] << " ";
			else
				cout << ans[i];
		}
		cout << endl;
	}
}