#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

void matrix_mul(double result[20][20], double A[20][20], double B[20][20], int m, int n, int p)
{
	for(int i = 1 ; i <= m ; ++i)
		for(int j = 1 ; j <= p ; ++j)
			result[i][j] = 0.0;

	for(int i = 1 ; i <= m ; ++i)
		for(int j = 1 ; j <= p ; j++)
		{
			for(int k = 1 ; k <= n ; ++k)
			{
				result[i][j] += A[i][k] * B[k][j];
			}
			if(abs(result[i][j]) < 0.0001)
				result[i][j] = 0.0;
		}

	return;
}


//QR Factorization
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << setprecision(4);
	double A[20][20] = {0.0};
	int m, n;
	cout << "Please enter your matrix's m, n:" << endl;
	cin >> m >> n;
	double Q[m + 1][n + 1] = {0.0}, R[m + 1][n + 1] = {0.0};
	cout << "Please enter the matrix:" << endl;
	for(int i = 1 ; i <= m ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			cin >> A[i][j];

	// cout << "A:" << endl;
	// for(int i = 1 ; i <= m ; i++)
	// {
	// 	for(int j = 1 ; j <= n ; j++)
	// 		cout << A[i][j] << " ";
	// 	cout << endl;
	// }

	for(int i = 1 ; i <= n ; ++i)
	{	
		double sum = 0.0;
		double length = 0.0;
		for(int j = 1 ; j <= m ; ++j)
			Q[j][i] = A[j][i];
		if(i > 1)
		{
			for(int j = 1 ; j < i ; ++j)
			{
				double mul = 0.0;
				for(int k = 1 ; k <= m ; ++k)
					mul += Q[k][j] * A[k][i];
				R[j][i] = mul;
				for(int k = 1 ; k <= m ; ++k)
					Q[k][i] -= Q[k][j] * mul;
			}
		}
		for(int j = 1 ; j <= m ; j++)
			sum += pow(Q[j][i], 2.0);
		length = sqrt(sum);
		R[i][i] = length;
		for(int j = 1 ; j <= m ; j++)
		{
			Q[j][i] /= length;
			if(abs(Q[j][i]) <= 0.0001)
				Q[j][i] = 0;
		}
	}

	cout << "\nthe Q is:" << endl;
	for(int i = 1 ; i <= m ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
			cout << Q[i][j] << " ";
		cout << endl;
	}
	cout << "\nthe R is:" << endl;
	for(int i = 1 ; i <= m ; i++)
	{
		for(int j = 1 ; j <= n ; j++)
			cout << R[i][j] << " ";
		cout << endl;
	}

}