#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a;
	while(cin >> a)
	{
		if(a == 0)
			break;
		if(a == 1)
			cout << "Discarded cards:" << endl << "Remaining card: 1" << endl;
		else
		{
			queue<int> q;
			for(int i = 1 ; i <= a ; i++)
				q.push(i);
			int ans[a - 1], cnt = 0;
			while(a - cnt > 1)
			{
				ans[cnt++] = q.front();
				q.pop();
				q.push(q.front());
				q.pop();
			}
			cout << "Discarded cards: ";
			for(int i = 0 ; i < cnt - 1 ; i++)
			{
				cout << ans[i] << ", ";
			}
			cout << ans[cnt - 1] << endl;
			cout << "Remaining card: " << q.front() << endl;
		}
	}
}