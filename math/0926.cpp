#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

double newton1(double x)
{
	double cur = x - (pow(x, 5) + x - 3) / (5 * pow(x, 4) + 1);
	double ans = pow(cur, 5) + cur - 3;
	if(ans > -0.0001 && ans < 0.0001)
		return cur;
	return newton1(cur);
}

double newton2(double x)
{
	double cur = x - (log(x) + 2 * pow(x, 2) - 3) / ((1.0 / x) + 4 * x);
	double ans = log(cur) + 2 * pow(cur, 2) - 3;
	if(ans > -0.0001 && ans < 0.0001)
		return cur;
	return newton2(cur);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "x^5 + x = 3\nx = " << newton1(1.0) << "\n\n";
	cout << "lnx + 2x^2 = 3\nx = " << newton2(1.0) << "\n";
}