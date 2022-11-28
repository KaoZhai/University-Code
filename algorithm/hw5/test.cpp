#include <bits/stdc++.h>
#define MAX 1010
using namespace std;

int mapp[MAX][MAX] = {0};
int N, M;
vector<int> mapi, mapj;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int sec;
	cin >> N >> M >> sec;
	char stati;
	for(int i = 1 ; i <= N ; i++)
	{
		for(int j = 1 ; j <= M ; j++)
		{
			cin >> stati;
			if(stati == 'L')
				mapp[i][j] = 2;
			else if(stati == 'O')
				mapp[i][j] = -1;
			else if(stati == 'C')
				mapp[i][j] = 0;
		}
	}

	for(int i = 0 ; i < sec ; i++)
	{
		for(int j = 1 ; j <= N ; j++)
		{
			for(int k = 1 ; k <= M ; k++)
			{
				if(mapp[j][k] > 0)
				{
					if(mapp[j - 1][k] == 0)
					{
						mapi.push_back(j - 1);
						mapj.push_back(k);
					}
					if(mapp[j][k - 1] == 0 )
					{
						mapi.push_back(j);
						mapj.push_back(k - 1);
					}
					if(mapp[j + 1][k] == 0)
					{
						mapi.push_back(j + 1);
						mapj.push_back(k);
					}
					if(mapp[j][k + 1] == 0)
					{
						mapi.push_back(j);
						mapj.push_back(k + 1);
					}
				}
			}
		}
		// for(int j = 1 ; j <= N ; j++)
		// {
		// 	for(int k = 1 ; k <= M ; k++)
		// 		cout << mapp[j][k] << " ";
		// 	cout << endl;
		// }
		// cout << endl;
		if(mapi.empty() && mapj.empty())
			break;
		else
		{
			while(!mapi.empty())
			{
				mapp[mapi.back()][mapj.back()] = 1;
				mapi.pop_back();
				mapj.pop_back();
			}
		}
	}
	for(int i = 1 ; i <= N ; i++)
	{
		for(int j = 1 ; j <= M ; j++)
		{
			if(mapp[i][j] == 2)
				cout << "L";
			else if(mapp[i][j] == 1)
				cout << "X";
			else if(mapp[i][j] == 0)
				cout << "C";
			else if(mapp[i][j] == -1)
				cout << "O";
		}
		cout << endl;
	}
}