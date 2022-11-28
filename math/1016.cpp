#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;


double num[4][4] = {0.0};

int gcd(int a, int b)
{
	if(b) while((a %= b) && (b %= a));
	return a + b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double L[4][4] = {0.0}, U[4][5] = {0.0};
	double b[4];

	cout << "Please enter a 4 by 4 matrix: " << endl;
	for(int i = 0 ; i < 4 ; i++)
		for(int j = 0 ; j < 4 ; j++)
		{
			cin >> num[i][j];
			L[i][j] = 0.0;
			U[i][j] = num[i][j];
		}

	cout << "Please enter B:" << endl;
	for(int i = 0 ; i < 4 ; i++)
		cin >> U[i][4];

	//U
	// cout << "\nU:\n";
	for(int x = 0 ; x < 3 ; x++)
	{
		for(int y = x + 1 ; y < 4 ; y++)
		{
			if(U[y][x] != 0)
			{
				double col = 0.0;
				if(U[x][x] != 0)
					col = U[y][x] / U[x][x];
				else
					col = 0.0;
				L[y][x] = col;

				for(int xx = x ; xx < 5 ; xx++)
				{
					U[y][xx] = U[y][xx] - (U[x][xx] * col);
					if(U[y][xx] - 0 > -0.00001 && U[y][xx] - 0 < 0.00001)
						U[y][xx] = 0.0;
				}
			}
		}
	}
	// for(int ii = 0 ; ii < 4 ; ii++)
	// {
	// 	for(int jj = 0 ; jj < 5 ; jj++)
	// 	{
	// 		cout << U[ii][jj] << " ";
	// 	}
	// 	cout << "\n";
	// }
	double ans[4] = {0.0};
	for(int i = 3 ; i >= 0 ; i--)
	{
		ans[i] = U[i][4] / U[i][i];
		for(int j = i - 1 ; j >= 0 ; j--)
		{
			if(U[j][i] != 0)
			{
				U[j][4] -= U[j][i] * ans[i];
				U[j][i] = 0;
			}
		}
	}
	cout << "x = " << ans[0] << endl;
	cout << "y = " << ans[1] << endl;
	cout << "z = " << ans[2] << endl;
	cout << "w = " << ans[3] << endl;
	// cout << "\nL:\n";
	// for(int ii = 0 ; ii < 4 ; ii++)
	// {
	// 	for(int jj = 0 ; jj < 4 ; jj++)
	// 	{
	// 		if(ii == jj)
	// 			L[ii][jj] = num[ii][jj];
	// 		cout << L[ii][jj] << " ";
	// 	}
	// 	cout << "\n";
	// }



}