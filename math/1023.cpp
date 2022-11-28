#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

typedef struct _matrix{
	int row;//x
	int column;//y
	double num[10][10];
}matrix;

void swap_row(matrix *A, matrix *B, matrix *P, int a, int b)
{
	for(int i = 1 ; i <= A -> row ; ++i)
	{
		swap(A -> num[a][i], A -> num[b][i]);
		swap(P -> num[a][i], P -> num[b][i]);
	}
	swap(B -> num[1][a], B -> num[1][b]);
	return;
}

void reduce(matrix *A, matrix *B, matrix *P)
{
	int max;

	for(int cur = 1 ; cur <= A -> column - 1 ; cur++)
	{
		max = cur;
		for(int i = cur ; i <= A -> row ; i++)
		{
			if(abs(A -> num[i][cur]) > abs(A -> num[max][cur]))
				max = i;
		}
		swap_row(A, B, P, cur, max);

		for(int i = cur + 1 ; i <= A -> row ; i++)
		{
			A -> num[i][cur] /= A -> num[cur][cur];
			for(int j = cur + 1 ; j <= A -> column ; ++j)
				A -> num[i][j] -= (A -> num[i][cur] * A -> num[cur][j]);
		}
	}
}

//LU
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a_row, a_column;
	cout << "Please enter how many rows A has:" << endl;
	cin >> a_row;
	cout << "Please enter how many column A has:" << endl;
	cin >> a_column;

	matrix A{a_row, a_column, {0.0}};
	matrix Atmp{a_row, a_column, {0.0}};
	matrix U{a_row, a_column, {0.0}};
	matrix L{a_row, a_column, {0.0}};

	cout << "Please enter the elements of A:" << endl;
	for(int i = 1 ; i <= A.column ; ++i)
		for(int j = 1 ; j <= A.row ; ++j)
			cin >> A.num[i][j];

	Atmp = A;
	matrix P{a_row, a_row, {0.0}};
	for(int i = 1 ; i <= P.row ; ++i)
		P.num[i][i] = 1;

	matrix B{2, a_column, {0.0}};
	cout << "Please enter the elements of B:" << endl;
	for(int i = 1 ; i <= B.column ; ++i)
		cin >> B.num[i][1];

	reduce(&A, &B, &P);

	printf("L:\n");
	for(int i = 1 ; i <= A.row ; ++i)
	{
		for(int j = 1 ; j <= A.column ; ++j)
		{
			if(i > j)
				L.num[i][j] = A.num[i][j];
			else if(i == j)
				L.num[i][j] = 1.000;
			else
				L.num[i][j] = 0.000;
			printf("%.3lf ", L.num[i][j]);
		}
		printf("\n");
	}
	
	printf("U:\n");
	for(int i = 1 ; i <= A.row ; ++i)
	{
		for(int j = 1 ; j <= A.column ; ++j)
		{
			if(j >= i)
				U.num[i][j] = A.num[i][j];
			else
				U.num[i][j] = 0.000;
			printf("%.3lf ", U.num[i][j]);
		}
		printf("\n");
	}
	printf("P:\n");
	for(int i = 1 ; i <= P.row ; ++i)
	{
		for(int j = 1 ; j <= P.column ; ++j)
			printf("%.0lf ", P.num[i][j]);
		printf("\n");
	}
	A = Atmp;
}