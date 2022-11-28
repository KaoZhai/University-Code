#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

//log(x) = lnx
//exp(x) = e^x
//log10(x) = log_10 x

int n = 0;

/*	//bisection function
	double f(double x)
	{
		return f(x);
	}

	double bisection(double a, double b, double f_ans)
	{
		double mid = (a + b) / 2;
		double cur = f(mid);
		if(cur - f_ans > 0.000001)										return bisection(a, mid, f_ans);
		else if((cur - f_ans < 0.000001) && (cur - f_ans > -0.000001))	return mid;
		else		 													return bisection(mid, b, f_ans);
	}
*/

/*	//fixed_point function
	double g(double x)
	{
		return g(x);
	}

	double fixed_point(double cur, double pre)
	{
		//function of g(x) = x
		cur = g(cur);

		if(abs(cur - pre) < 0.0001)
			return cur;
		return fixed_point(cur, cur);
	}
*/

/*	//newton function
	double f(double x)
	{
		return f(x);
	}

	double df(double x)
	{
		return df(x);
	}

	double newton(double cur)
	{
		//x_i+1 = x_i - f(x_i)/df(x_i)
		double curans = 0.0;

		cur = cur - (f(cur) / df(cur));
		curans = f(cur);

		if((curans < 0.0001) && (curans > -0.0001))	return cur;
		return newton(cur);
	}
*/

/*	//LUP function
	typedef struct _matrix{
	int row;		//x
	int column;		//y
	double num[15][15];
	}matrix;

	//multipul two matrix
	void matrix_mul(matrix *A, matrix *B, matrix *C)
	{
		matrix mul_tmp{C -> row, C -> column, {0.0}};

		for(int i = 1 ; i <= mul_tmp.row ; ++i)
			for(int j = 1 ; j < mul_tmp.column ; ++j)
				for(int k = i ; k <= A -> column ; ++k)
					mul_tmp.num[i][j] += A -> num[i][k] * B -> num[k][j];

		for(int i = 1 ; i <= C -> row ; ++i)
			for(int j = 1 ; j <= C -> column ; ++j)
				C -> num[i][j] = mul_tmp.num[i][j];

		return;
	}

	//swap row a, b in A, B, P matrix
	void swap_row(matrix *A, matrix *B, matrix *P, int a, int b)
	{
		for(int i = 1 ; i <= A -> row ; ++i)
		{
			swap(A -> num[a][i], A -> num[b][i]);
			swap(P -> num[a][i], P -> num[b][i]);
		}
		swap(B -> num[a][1], B -> num[b][1]);
		return;
	}

	//reduce all A matrix
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
*/

/*	//Jacobi function
	void matrix_mul(double P[11][11], double ans[11])
	{
		double tmp[11] = {0.0};

		for(int i = 1 ; i <= n ; ++i)
			for(int j = 1 ; j <= n ; ++j)
				tmp[i] += P[i][j] * ans[j];

		for(int i = 1 ; i <= n ; ++i)
			ans[i] = tmp[i];

		return;
	}

	void cal(double A[11][11], double B[11], double LU[11][11], double D[11][11], double ans[11])
	{
		double pre[11];
		int flag;
		int cnt = 0;
		while(1)
		{
			cnt++;
			for(int i = 1 ; i <= n ; ++i)
				pre[i] = ans[i];

			matrix_mul(LU ,ans);

			for(int i = 1 ; i <= n ; ++i)
				ans[i] = B[i] - ans[i];

			matrix_mul(D, ans);
			
			cout << cnt << "time(s) result:" << endl;
			for(int i = 1 ; i <= n ; ++i)
				cout << fixed << setprecision(4) << ans[i] << " ";
			cout << endl;

			flag = 0;
			for(int i = 1 ; i <= n ; ++i)
			{
				if(abs(ans[i] - pre[i]) > 0.00001)
				{
					flag = 1;
					break;
				}
			}
			if(!flag)
				return;
		}
	}
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << fixed << setprecision(4);

/*	//horner's method || e.g. 2x^4 + 3x^3 - 3x^2 + 5x - 1 = -1 + x(5 + x(-3 + x(3 + 2x)))
	
	double x = 0.0;
	double ans = 0.0;

	//input
	cout << "please enter x= " << endl;	
	cin >> x;

	// function start
	ans = x;
	for(int i = 1 ; i < 50 ; i++)
	{
		ans += 1;
		ans *= x;
	}
	ans++;
	// function end

	//output
	cout << fixed << setprecision(4) << ans << endl;
*/

/*	//bisection(use functions start at line 12)
	
	double a, b, f_ans;

	//input
	cout << "Please enter the range a and b:" << endl;
	cin >> a >> b;
	cout << "Please enter the function answer:" << endl;
	cin >> f_ans;

	//output
	cout << "x = " << fixed << setprecision(4) << bisection(a, b, f_ans) << endl;
*/

/*	//Fixed-point iteration(use functions start at line 28)
	
	double ori = 0.0;

	//input
	cout << "Please enter the original x:" << endl;
	cin >> ori;

	cout << "the answer of x is: " << fixed << setprecision(4) << fixed_point(ori, ori) << endl;
*/

/*	//newton || let f(x) = 0 || initial guess x_0 need to close to the root(use functions start at line 45)

	cout << "x = " << fixed << setprecision(4) << newton(0.0) << endl;
*/

/*	//LUP(use function start at line 69)

	int a_row, a_column;

	//input A's row and coulumn amount
	cout << "Please enter how many rows A has:" << endl;
	cin >> a_row;
	cout << "Please enter how many column A has:" << endl;
	cin >> a_column;

	//anouce matrixes
	matrix A{a_row, a_column, {0.0}};
	matrix Atmp{a_row, a_column, {0.0}};
	matrix U{a_row, a_column, {0.0}};
	matrix L{a_row, a_column, {0.0}};
	matrix P{a_row, a_row, {0.0}};
	matrix B{2, a_column, {0.0}};
	matrix C{2, a_column, {0.0}};
	matrix X{2, a_column, {0.0}};
	
	//input A matrix, make Atmp
	cout << "Please enter the elements of A:" << endl;
	for(int i = 1 ; i <= A.column ; ++i)
		for(int j = 1 ; j <= A.row ; ++j)
			cin >> A.num[i][j];	
	Atmp = A;

	//generate P's initial format
	for(int i = 1 ; i <= P.row ; ++i)
		P.num[i][i] = 1;

	//input B matrix
	cout << "Please enter the elements of B:" << endl;
	for(int i = 1 ; i <= B.column ; ++i)
		cin >> B.num[i][1];

	//reduce matrix
	reduce(&A, &B, &P);

	//generate L + output L
	printf("\nL:\n");
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
	
	//generate U + output U
	printf("\nU:\n");
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

	//output P
	printf("\nP:\n");
	for(int i = 1 ; i <= P.row ; ++i)
	{
		for(int j = 1 ; j <= P.column ; ++j)
			printf("%.0lf ", P.num[i][j]);
		printf("\n");
	}

	//Let A return to original state
	A = Atmp;

	//get C + output C
	for(int i = 1 ; i <= C.column ; ++i)
	{
		for(int j = 1 ; j < i ; ++j)
		{
			B.num[i][1] -= C.num[j][1] * L.num[i][j];
		}
		C.num[i][1] = B.num[i][1];
	}
	cout << "\nC:" << endl;
	for(int i = 1 ; i <= C.column ; ++i)
		cout << C.num[i][1] << " ";
	cout << endl;

	//get X + output X
	for(int i = C.column ; i >= 1 ; --i)
	{
		for(int j = C.column ; j > i ; --j)
		{
			C.num[i][1] -= X.num[j][1] * U.num[i][j];
		}
		X.num[i][1] = C.num[i][1] / U.num[i][i];
	}
	cout << "\nX:" << endl;
	for(int i = 1 ; i <= X.column ; ++i)
		cout << X.num[i][1] << " ";
	cout << endl;
*/

/*	//Jacobi(use function start at line 130)
	double B[11] = {0.0}, A[11][11] = {0.0}, LU[11][11] = {0.0}, D[11][11] = {0.0}, ans[11] = {0.0};
	cout << "Please enter n:" << endl;
	cin >> n;
	cout << "Please enter the matrix:" << endl;
	for(int i = 1 ; i <= n ; ++i)
		for(int j = 1 ; j <= n ; ++j)
		{
			cin >> A[i][j];
			if(i == j)
				D[i][j] = 1 / A[i][j];
			else
				LU[i][j] = A[i][j];
		}

	cout << "Please enter B:" << endl;
	for(int i = 1 ; i <= n ; ++i)
		cin >> B[i];

	cal(A, B, LU, D, ans);

	for(int i = 1 ; i <= n ; ++i)
		cout << fixed << setprecision(4) << "x" << i << " = " << ans[i] << endl;
*/

}