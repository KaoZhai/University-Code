#include <bits/stdc++.h>

using namespace std;

int64_t mini = 2147483647;
int64_t shortp[310][310];
int N, M;

void init(int n)
{
	for(int i = 0 ; i <= n ; i++)
		for(int j = 0 ; j <= n ; j++)
			shortp[i][j] = 2147483647;
	return;
}

void floyd()
{
	for(int k = 1 ; k <= N ; k++)
		for(int i = 1 ; i <= N ; i++)
			for(int j = 1 ; j <= N ; j++)
				if(shortp[i][j] > shortp[i][k] + shortp[k][j])
					shortp[i][j] = shortp[i][k] + shortp[k][j];
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	init(N + 1);

	int edge1, edge2, weight;

	for(int i = 0 ; i < M ; i++)
	{
		cin >> edge1 >> edge2 >> weight;
		shortp[edge1][edge2] = weight;
	}

	floyd();

	// for(int i = 1 ; i <= N ; i++)
	// {
	// 	for(int j = 1 ; j <= N ; j++)
	// 		cout << shortp[i][j] << " ";
	// 	cout << endl;
	// }

	int ch = 0;

	for(int i = 1 ; i <= N ; i++)
	{
		if(shortp[i][i] < mini)
		{
			mini = shortp[i][i];
			ch = 1;
		}
	}

	if(ch)
		cout << mini << endl;
	else
		cout << "-1" << endl;
}