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

void initDr(double Dr[20][20])
{
	for(int i = 0 ; i < 20 ; ++i)
		for(int j = 0 ; j < 20 ; ++j)
			Dr[i][j] = 0.0;
	return;
}

void initDrT(double DrT[20][20])
{
	for(int i = 0 ; i < 20 ; ++i)
		for(int j = 0 ; j < 20 ; ++j)
			DrT[i][j] = 0.0;
	return;
}

void initr(double r[20][20])
{
	for(int i = 0 ; i < 20 ; ++i)
		for(int j = 0 ; j < 20 ; ++j)
			r[i][j] = 0.0;
	return;
}

double S(int num, double x[20][20], double input[20][20])
{
	return sqrt((x[1][1] - input[num][1])*(x[1][1] - input[num][1])+(x[2][1] - input[num][2])*(x[2][1] - input[num][2]));
}

void getDr(double Dr[20][20], double x[20][20], double input[20][20])
{
	for(int i = 1 ; i <= 3 ; ++i)
	{
		for(int j = 1 ; j <= 2 ; ++j)
		{
			// cout << "x[j][1] - input[i][1] = " << x[j][1] - input[i][1] << endl;
			// cout << "S(i, x, input) = " << S(i, x, input) << endl;
			Dr[i][j] = (x[j][1] - input[i][j]) / S(i, x, input);
			// cout << "Dr[i][j] = " << Dr[i][j] << endl;
		}
	}

	cout << "\nDr:" << endl;
	for(int i = 1 ; i <= 3 ; ++i)
	{
		for(int j = 1 ; j <= 2 ; ++j)
			cout << Dr[i][j] << " ";
		cout << endl;
	}
	return;
}

void getDrT(double Dr[20][20], double DrT[20][20])
{
	for(int i = 0 ; i < 20 ; ++i)
		for(int j = 0 ; j < 20 ; ++j)
			DrT[i][j] = Dr[j][i];

	// cout << "\nDrT:" << endl;
	// for(int i = 1 ; i <= 2 ; ++i)
	// {
	// 	for(int j = 1 ; j <= 3 ; ++j)
	// 		cout << DrT[i][j] << " ";
	// 	cout << endl;
	// }
	return;
}

void getr(double r[20][20], double x[20][20], double input[20][20])
{
	for(int i = 1 ; i <= 3 ; ++i)
		r[i][1] = S(i, x, input) - input[i][3];

	cout << "\nr:" << endl;
	for(int i = 1 ; i <= 3 ; ++i)
		cout << r[i][1] << endl;
	return;
}

void getDrTDr(double DrTDr[20][20], double Dr[20][20], double DrT[20][20])
{
	matrix_mul(DrTDr, DrT, Dr, 2, 3, 2);

	cout << "\nDrTDr:" << endl;
	for(int i = 1 ; i <= 2 ; ++i)
	{
		for(int j = 1 ; j <= 2 ; ++j)
			cout << DrTDr[i][j] << " ";
		cout << endl;
	}
	return;
}

void getDrTmr(double DrTmr[20][20], double DrT[20][20], double r[20][20])
{
	matrix_mul(DrTmr, DrT, r, 2, 3, 1);

	for(int i = 0 ; i < 20 ; ++i)
		for(int j = 0 ; j < 20 ; ++j)
			DrTmr[i][j] = -DrTmr[i][j];

	cout << "\nDrTmr:" << endl;
	for(int i = 1 ; i <= 2 ; ++i)
		cout << DrTmr[i][1] << endl;
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	//variable
	double input[20][20] = {0.0};
	double x[20][20] = {0.0};
	double Dr[20][20] = {0.0}, DrT[20][20] = {0.0};
	double r[20][20] = {0.0};
	double prex = 0.0, prey = 0.0;
	double DrTDr[20][20] = {0.0};
	double DrTmr[20][20] = {0.0};
	double v[20][20] = {0.0};

	//input
	cout << fixed << setprecision(4) << "Please enter the first circle's center and radius(x,y,r):" << endl;
	cin >> input[1][1] >> input[1][2] >> input[1][3];
	cout << "Please	 enter the second circle's center and radius(x,y,r):" << endl;
	cin >> input[2][1] >> input[2][2] >> input[2][3];
	cout << "Please	 enter the third circle's center and radius(x,y,r):" << endl;
	cin >> input[3][1] >> input[3][2] >> input[3][3];

	//find answer
	while(1)
	{
		//copy previous
		prex = x[1][1];
		prey = x[2][1];

		//init
		initDr(Dr);
		initDrT(DrT);
		initr(r);

		//get everything
		getDr(Dr, x, input);
		getDrT(Dr, DrT);
		getr(r, x, input);
		getDrTDr(DrTDr, Dr, DrT);
		getDrTmr(DrTmr, DrT, r);

		//calculate v
		v[1][1] = DrTmr[1][1] / DrTDr[1][1];
		v[2][1] = DrTmr[2][1] / DrTDr[2][2];
		cout << "\nv1 = " << v[1][1] << endl;
		cout << "v2 = " << v[2][1] << endl;

		//plus x
		x[1][1] += v[1][1];
		x[2][1] += v[2][1];

		//check break
		if((abs(prex - x[1][1]) <= 0.0001) && (abs(prey - x[2][1]) <= 0.0001))
			break;
	}

	//output answer
	cout << "\nx = " << x[1][1] << " y = " << x[2][1];
}