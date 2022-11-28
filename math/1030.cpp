#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

void matrix_mul(double P[11][11], double ans[11])
{
	double tmp[11] = {0.0};

	for(int i = 1 ; i <= 10 ; ++i)
		for(int j = 1 ; j <= 10 ; ++j)
			tmp[i] += P[i][j] * ans[j];

	for(int i = 1 ; i <= 10 ; ++i)
		ans[i] = tmp[i];

	return;
}

void cal(double A[11][11], double B[11], double LU[11][11], double D[11][11], double ans[11])
{
	double pre[11];
	int flag;
	while(1)
	{
		for(int i = 1 ; i <= 10 ; ++i)
			pre[i] = ans[i];

		matrix_mul(LU ,ans);

		for(int i = 1 ; i <= 10 ; ++i)
			ans[i] = B[i] - ans[i];

		matrix_mul(D, ans);

		flag = 0;
		for(int i = 1 ; i <= 10 ; ++i)
		{
			if(abs(ans[i] - pre[i]) > 0.0000001)
			{
				flag = 1;
				break;
			}
		}
		if(!flag)
			return;
	}
}

//iterative methods
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double B[11] = {0.0}, A[11][11] = {0.0}, LU[11][11] = {0.0}, D[11][11] = {0.0}, ans[11] = {0.0};
	cout << "Please enter the matrix:" << endl;
	for(int i = 1 ; i <= 10 ; ++i)
		for(int j = 1 ; j <= 10 ; ++j)
		{
			cin >> A[i][j];
			if(i == j)
				D[i][j] = 1 / A[i][j];
			else
				LU[i][j] = A[i][j];
		}

	cout << "Please enter B:" << endl;
	for(int i = 1 ; i <= 10 ; ++i)
		cin >> B[i];

	cal(A, B, LU, D, ans);

	for(int i = 1 ; i <= 10 ; ++i)
		cout << "x" << i << " = " << ans[i] << endl;
}