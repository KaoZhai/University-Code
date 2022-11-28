#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define pi 3.14159265358979

using namespace std;

void generate_both_A(int t, double A[20][20], double At[20][20])
{
	for(int i = 1 ; i <= t ; i++)
	{
		A[i][1] = 1;
		A[i][2] = cos(2 * pi * (double)(i - 1) / 12);
		A[i][3] = sin(2 * pi * (double)(i - 1) / 12);
		A[i][4] = cos(4 * pi * (double)(i - 1) / 12);
	}

	for(int i = 1 ; i <= t ; i++)
		for(int j = 1 ; j <= 4 ; j++)
			At[j][i] = A[i][j];
}

void matrix_mul(double result[20][20], double A[20][20], double B[20][20], int a, int b, int c)
{
	for(int i = 1 ; i <= a ; i++)
		for(int j = 1 ; j <= c ; j++)
		{
			for(int k = 1 ; k <= b ; k++)
				result[i][j] += A[i][k] * B[k][j];
		}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << setprecision(4);
	int t;
	double matrix_A[20][20] = {0.0};
	double matrix_B[20][20] = {0.0};
	double matrix_At[20][20] = {0.0};
	double c[20][20] = {0.0};
	double AAt[20][20] = {0.0};
	double AtB[20][20] = {0.0};
	double BB[20][20] = {0.0};
	double RMSE = 0.0;
	cout << "Please enter how many data input you have:" <<endl;
	cin >> t;
	for(int i = 1 ; i <= t ; i++)
	{
		cout << "Please enter your " << i << " data:" << endl;
		cin >> matrix_B[i][1];
	}

	generate_both_A(t, matrix_A, matrix_At);

	matrix_mul(AAt, matrix_At, matrix_A, 4, t, 4);
	matrix_mul(AtB, matrix_At, matrix_B, 4, t, 1);

	// cout << "matrix_A:\n";
	// for(int i = 1 ; i <= t ; i++)
	// {
	// 	for(int j = 1 ; j <= 4 ; j++)
	// 		cout << matrix_A[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << "matrix_At:\n";
	// for(int i = 1 ; i <= 4 ; i++)
	// {
	// 	for(int j = 1 ; j <= t ; j++)
	// 		cout << matrix_At[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << "matrix_AAt:\n";
	// for(int i = 1 ; i <= 4 ; i++)
	// {
	// 	for(int j = 1 ; j <= 4 ; j++)
	// 		cout << AAt[i][j] << " ";
	// 	cout << endl;
	// }

	// cout << "matrix_AtB:\n";
	// for(int i = 1 ; i <= 4 ; i++)
	// {
	// 		cout << AtB[i][1] << " ";
	// 	cout << endl;
	// }

	cout << "\n";
	for(int i = 1 ; i <= 4 ; i++)
	{
		c[i][1] = AtB[i][1] / AAt[i][i];
		cout << "c" << i << " = " << c[i][1] << endl;
	}

	matrix_mul(BB, matrix_A, c, 12, 4, 1);

	cout << "matrix_BB:\n";
	for(int i = 1 ; i <= 4 ; i++)
	{
			cout << BB[i][1] << " ";
		cout << endl;
	}

	for(int i = 1 ; i <= t ; i++)
	{
		RMSE += pow(matrix_B[i][1] - BB[i][1],2);
	}
	RMSE = sqrt(RMSE / 12);
	cout << "\nRMSE: " << RMSE << endl;
}