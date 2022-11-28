#include <bits/stdc++.h>

using namespace	std;

queue<int> mapi, mapj;
int mapp[3010][3010];
int K, cnt = 0, sec = 0;

void bfs(int N, int M)
{
	int nowi, nowj, cur;
	while(1)
	{
		if(sec == K)
			break;
		cur = cnt;
		cnt = 0;
		for(int i = 0 ; i < cur ; i++)
		{
			nowi = mapi.front();
			nowj = mapj.front();
			if(nowi - 1 > 0 && mapp[nowi - 1][nowj] == 0)
			{
				mapi.push(nowi - 1);
				mapj.push(nowj);
				mapp[nowi - 1][nowj] = 1;
				cnt++;
			}
			if(nowi + 1 <= N && mapp[nowi + 1][nowj] == 0)
			{
				mapi.push(nowi + 1);
				mapj.push(nowj);
				mapp[nowi + 1][nowj] = 1;
				cnt++;
			}
			if(nowj - 1 > 0 && mapp[nowi][nowj - 1] == 0)
			{
				mapi.push(nowi);
				mapj.push(nowj - 1);
				mapp[nowi][nowj - 1] = 1;
				cnt++;
			}
			if(nowj + 1 <= M && mapp[nowi][nowj + 1] == 0)
			{
				mapi.push(nowi);
				mapj.push(nowj + 1);
				mapp[nowi][nowj + 1] = 1;
				cnt++;
			}
			mapi.pop();
			mapj.pop();
		}
		if(cnt == 0)
			break;
		sec++;
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M >> K;

	char input[M];

	for(int i = 1 ; i <= N ; i++)
	{
		cin >> input;
		for(int j = 1 ; j <= M ; j++)
		{
			if(input[j - 1] == 'O')
				mapp[i][j] = -1;
			else if(input[j - 1] == 'L')
			{
				mapp[i][j] = 2;
				mapi.push(i);
				mapj.push(j);
				cnt++;
			}
		}
	}

	bfs(N, M);

	for(int i = 1 ; i <= N ; i++)
	{
		for(int j = 1 ; j <= M ; j++)
		{
			if(mapp[i][j] == 1)
				input[j - 1] = 'X';
			else if(mapp[i][j] == 0)
				input[j - 1] = 'C';
			else if(mapp[i][j] == -1)
				input[j - 1] = 'O';
			else
				input[j - 1] = 'L';
		}
		cout << input << endl;
	}
}