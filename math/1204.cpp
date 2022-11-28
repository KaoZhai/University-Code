#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	double inputx = 0.0;
	double x[5] = {0.0, 1800.0, 1850.0, 1900.0, 2000.0};
	double y[5] = {0.0, 280.0, 283.0, 291.0, 370.0};
	double ans[5][5] = {0.0};
	double output = 0.0;

	for(int i = 1 ; i <= 4 ; ++i)
		ans[i][1] = y[i];

	// for(int i = 1 ; i <= 4 ; ++i)
	// {
	// 	for(int j = 1 ; j <= 4 ; ++j)
	// 		cout << ans[i][j] << " ";
	// 	cout << endl;
	// }

	for(int i = 2 ; i <= 4 ; ++i)
	{
		for(int j = 1 ; j <= 5 - i ; ++j)
		{
			// cout << "i = " << i << " j = " << j << endl;
			// cout << "(ans[j + 1][i - 1] - ans[j][i - 1]) = " << (ans[j + 1][i - 1] - ans[j][i - 1]);
			// cout << "\n(x[i + j - 1] - x[j]) = " << (x[i + j - 1] - x[j]) << endl;
			ans[j][i] = (ans[j + 1][i - 1] - ans[j][i - 1]) 
						/ (x[i + j - 1] - x[j]);
		}
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
	for(int i = 4 ; i >= 1 ; --i)
	{
		output += ans[1][i];
		if(i != 1)
			output *= (inputx - x[i - 1]);
	}

	cout << "the answer is: " << output << endl;
}