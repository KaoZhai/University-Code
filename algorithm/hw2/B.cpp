#include <bits/stdc++.h>

using namespace std;

int64_t cnt = 0;
int tmp[200010];
void merge_sort(int *a, int n)
{
	if(n <= 1) return;

	int m = n / 2;
	merge_sort(a, m);
	merge_sort(a + m, n - m);

	for(int i = 0, l = 0, r = m ; i < n ; i++)
	{
		if((l < m && a[l] < a[r]) || r == n)
			tmp[i] = a[l++];
		else
		{
			tmp[i] = a[r++];
			cnt += m - l;
		}
	}

	for(int i = 0 ; i < n ; i++)
		a[i] = tmp[i];

	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	while(cin >> t)
	{
		cnt = 0;
		int st = t / 2;
		int even[t - st], odd[st];
		for(int i = 0 ; i < t ; i++)
		{
			if(i & 1)
				cin >> odd[i / 2];
			else
				cin >> even[i / 2];
		}

		merge_sort(odd, st);
		merge_sort(even, t - st);

		int check = 1;
		for(int i = 0 ; i < t ; i++)
		{
			if(i & 1)
				tmp[i] = odd[i / 2];
			else
				tmp[i] = even[i / 2];
		}
		for(int i = 1 ; i < t ; i++)
			if(tmp[i] < tmp[i - 1])
			{
				check = 0;
				break;
			}
		if(check)
			cout << "yes" << endl << cnt << endl;
		else
			cout << "no" << endl << cnt << endl;
	}
}