#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

//reduce all A matrix
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
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
		A[1][1] = 1;//f1 dx
		A[1][2] = 1;//f1 dy
		A[1][3] = 1;//f1 dz
		A[2][1] = 2 * curx;//f2 dx
		A[2][2] = 2 * cury;//f2 dy
		A[2][3] = 2 * curz;//f2 dz
		A[3][1] = exp(curx) + cury - curz;//f3 dx
		A[3][2] = curx;//f3 dy
		A[3][3] = -curx;//f3 dz
		B[1] = -(curx + cury + curz - 3);//-(f1-b)
		B[2] = -(pow(curx, 2) + pow(cury, 2) + pow(curz, 2) - 5);//-(f2-b)
		B[3] = -(exp(curx) + curx * cury - curx * curz - 1);//-(f3-b)
		reduce(A,B);

		// for(int i = 1 ; i <= 3 ; i++)
		// {
		// 	for(int j = 1 ; j <= 3 ; j++)
		// 	// 	cout << A[i][j] << " ";
			// cout << endl;
		// }
		// cout << endl;
		// for(int i = 1 ; i <= 3 ; i++)
		// 	cout << B[i] << " ";
		// cout << endl;

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
}