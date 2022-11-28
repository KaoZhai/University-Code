#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

/* //sloving nonlinear problem function
	void reduce(double A[4][4], double B[4])
	{
		for(int i = 1 ; i <= 2 ; i++)
		{
			for(int j = i + 1 ; j <= 3 ; j++)
			{
				double mul = A[j][i] / A[i][i];
				if(abs(mul) <= 0.0001)
					mul = 0.0;
				B[j] -= B[i] * mul;
				for(int k = i ; k <= 3 ; k++)
				{
					A[j][k] -= A[i][k] * mul;
				}
			}
		}
	}
*/

/* //Least squares function
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
*/

/* //QR Factorization function
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
*/

/* //Gauss-Newton method
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
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(4);

/*  //solving nonlinear problem (w/ line 6)
	double curx = 0.0, cury = 0.0, curz = 0.0;
	double prex = 0.0, prey = 0.0, prez = 0.0;
	double A[4][4] = {0.0};
	double B[4] = {0.0};
	double ans[4] = {0.0};
	cout << "please enter the initial x,y,z:" << endl;
	cin >> curx >> cury >> curz;
	while(1)
	{
		prex = curx;
		prey = cury;
		prez = curz;
		A[1][1] = 4 * curx - 4;//f1 dx
		A[1][2] = 2 * cury;//f1 dy
		A[1][3] = 6 * curz + 6;//f1 dz
		A[2][1] = 2 * curx;//f2 dx
		A[2][2] = 2 * cury - 2;//f2 dy
		A[2][3] = 4 * curz;//f2 dz
		A[3][1] = 6 * curx - 12;//f3 dx
		A[3][2] = 2 * cury;//f3 dy
		A[3][3] = 6 * curz;//f3 dz
		B[1] = -(2 * curx * curx - 4 * curx + cury * cury + 3 * curz * curz + 6 * curz + 2);//-(f1-b)
		B[2] = -(curx * curx + cury * cury - 2 * cury + 2 * curz * curz - 5);//-(f2-b)
		B[3] = -(3 * curx * curx - 12 * curx + cury * cury + 3 * curz * curz + 8);//-(f3-b)
		reduce(A,B);

		cout << "A:\n";
		for(int i = 1 ; i <= 3 ; i++)
		{
			for(int j = 1 ; j <= 3 ; j++)
				cout << A[i][j] << " ";
			cout << endl;
		}
		cout << endl;

		cout << "\nB:\n";
		for(int i = 1 ; i <= 3 ; i++)
			cout << B[i] << " ";
		cout << endl;

		ans[3] = B[3] / A[3][3];
		ans[2] = (B[2] - (A[2][3] * ans[3])) / A[2][2];
		ans[1] = (B[1] - (A[1][3] * ans[3]) - (A[1][2] * ans[2])) / A[1][1];
		// cout << endl;
		// for(int i = 1 ; i <= 3 ; i++)
		// 	cout << ans[i] << " ";
		curx += ans[1];
		cury += ans[2];
		curz += ans[3];
		if(abs(curx - prex) <= 0.00001 && abs(cury - prey) <= 0.00001 && abs(curz - prez) <= 0.00001)
			break;
	}
	if(abs(curx) <= 0.0001)
		curx = 0.0;
	if(abs(cury) <= 0.0001)
		cury = 0.0;
	if(abs(curz) <= 0.0001)
		curz = 0.0;
	cout << "the ans: x = " << curx << ", y = " << cury << ", z = " << curz << endl;
*/

/*	//Lagrange interpolation

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
*/

	//Newton’s divided differences

	double inputx = 0.0;
	double x[4] = {-1.0, 0.0, 1.0, 2.0};
	double y[4] = {1.0, 1.0, 2.0, 0.0};
	double ans[4][4] = {0.0};
	double output = 0.0;

	for(int i = 1 ; i <= 3 ; ++i)
		ans[i][1] = y[i];

	

	for(int i = 2 ; i <= 3 ; ++i)
	{
		for(int j = 1 ; j <= 4 - i ; ++j)
		{
			// cout << "i = " << i << " j = " << j << endl;
			// cout << "(ans[j + 1][i - 1] - ans[j][i - 1]) = " << (ans[j + 1][i - 1] - ans[j][i - 1]);
			// cout << "\n(x[i + j - 1] - x[j]) = " << (x[i + j - 1] - x[j]) << endl;
			ans[j][i] = (ans[j + 1][i - 1] - ans[j][i - 1]) 
						/ (x[i + j - 1] - x[j]);
		}
	}

	for(int i = 1 ; i <= 3 ; ++i)
	{
		for(int j = 1 ; j <= 3 ; ++j)
			cout << ans[j][i] << " ";
		cout << endl;
	}

	cout << "Please enter input x:" << endl;
	cin >> inputx;

	// for(int i = 1 ; i <= 4 ; ++i)
	// {
	// 	double tmp = ans[1][i];
	// 	for(int j = 1 ; j <= i - 1 ; ++j)
	// 		tmp *= (inputx - x[j]);
	// 	output += tmp;
	// }


	//Horner's rule
	for(int i = 3 ; i >= 1 ; --i)
	{
		output += ans[1][i];
		if(i != 1)
			output *= (inputx - x[i - 1]);
	}

	cout << "the answer is: " << output << endl;


/*	//Least squares (w/ line 26)

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
*/

/*	//QR Factorization

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
*/

/*	//Gauss-Newton method

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
*/

}