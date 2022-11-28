#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(4);

	int n = 0;

	cout << "Please enter the number of the points:" << endl;
	cin >> n;

	double pointx[n] = {0.0}, pointy[n] = {0.0};

	cout << "\nPlease enter those " << n << " points:" << endl;
	for(int i = 0 ; i < n ; i++)
		cin >> pointx[i] >> pointy[i];

	double x = 0.0;
	cout << "\nPlease enter the x you want to count:" << endl;
	cin >> x;

	double ans = 0.0;
	for(int i = 0 ; i < n ; i++)
	{
		double cur = pointy[i];
		for(int j = 0 ; j < n ; j++)
		{
			if(j != i)
			{
				cur *= (x - pointx[j]);
				cur /= (pointx[i] - pointx[j]);
			}
		}
		ans += cur;
	}

	cout << "\nthe answer "<< ans << endl;
}