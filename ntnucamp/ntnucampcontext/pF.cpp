#include <bits/stdc++.h>
using namespace std;
int uni[1010] = {};

struct nod
{
	int u, v, w;
};

void init(int x)
{
	for(int i = 0 ; i < x ; i++)
		uni[i] = i;
}

int find(int x)
{
	if(uni[x] == x)
		return x;
	return uni[x] = find(uni[x]);
}

void unio(int a, int b)
{
	a = find(a);
	b = find(b);
	if(a != b)
		uni[a] = b;
	return;
}

bool cmp(nod a, nod b)
{
	return a.w < b.w;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	while(cin >> a >> b)
	{
		if(a == 0 && b == 0)
			break;
		init(a);
		nod p[b] = {};
		int cnt = 0, ans[30000] = {};
		for(int i = 0 ; i < b ; i++)
			cin >> p[i].u >> p[i].v >> p[i].w;
		sort(p, p + b, cmp);
		for(int i = 0 ; i < b ; i++)
		{
			if(find(p[i].u) != find(p[i].v))
				unio(p[i].u, p[i].v);
			else
				ans[cnt++] = p[i].w;
		}
		sort(ans, ans + cnt);
		if(cnt)
		{
			for(int i = 0 ; i < cnt ; i++)
				cout << ans[i] << " \n"[i == (cnt - 1)];
		}
		else
			cout << "forest" << endl;
	}
}