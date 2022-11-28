#include <bits/stdc++.h>
using namespace std;

int main()
{
	int cnt = 0;
	while(++cnt)
	{
		int map[21][21] = {0};
		for(int i = 1 ; i < 20 ; i++)
		{
			int num;
			if(!(cin >> num)) return 0;
			for(int j = 0 ; j < num ; j++)
			{
				int n;
				cin >> n;
				map[i][n] = 1;
				map[n][i] = 1;
			}
		}
		int test, start, final;
		cout << "Test Set #" << cnt << "\n";
		cin >> test;
		while(test--)
		{
			int ans = 0, flag = 0;
			cin >> start >> final;
			bool visit[21] = {0};
			queue<int> search;
			search.push(start);
			search.push(0);
			while(1)
			{
				if(search.front() == 0)
				{
					ans++;
					search.pop();
					search.push(0);
				}
				if(search.front() == final)
					break;
				for(int i = 1 ; i < 21 ; i++)
					if(map[search.front()][i] && visit[i] == 0)
					{
						search.push(i);
						visit[i] = 1;
					}
				search.pop();
			}
			printf("%2d to %2d: %d\n", start, final, ans);
		}
		cout << endl;
	}
}