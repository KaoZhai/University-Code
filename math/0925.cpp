#include <bits/stdc++.h>
#define INT_MAX 2147483647

using namespace std;

double bisection1(double a, double b)
{
	double mid = (a + b) / 2;
	double cur = pow(mid, 3);
	if(cur - 9 > 0.0001)
		return bisection1(a, mid);
	else if((cur - 9 < 0.0001) && (cur - 9 > -0.0001))
		return mid;
	else
		return bisection1(mid, b);
}

double bisection2(double a, double b)
{
	double mid = (a + b) / 2;
	double hi = 1.0 / 3.0;
	double cur = mid - pow(mid, hi) - 2;
	if(cur > 0.0001)
		return bisection2(a, mid);
	else if(cur < 0.0001 && cur > -0.0001)
		return mid;
	else
		return bisection2(mid, b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout << "x^3 = 9" << "\n";
	cout << "x = " << bisection1(0.0, 9.0) << "\n\n";

	cout << "x - x^(1/3) - 2 = 0\n";
	cout << "x = " << bisection2(3.0, 4.0) << "\n";
}