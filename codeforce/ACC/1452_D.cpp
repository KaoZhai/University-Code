#include <bits/stdc++.h>
#define INT_MAX 2147483647
#define MOD %998244353
#define MAX 200010
using namespace std;

struct gcdstruct{  
	int64_t d;
	int64_t x;
	int64_t y;
};

int64_t xx[MAX], yy[MAX];
gcdstruct EXTENDED_EUCLID(int64_t a,int64_t b)
{
	gcdstruct aa,bb;
	if(b==0)
	{
		aa.d = a;
		aa.x = 1;
		aa.y = 0;
		return aa;
	}
	else
    {
		bb = EXTENDED_EUCLID(b,a%b); 
		aa.d = bb.d;
		aa.x = bb.y;
		aa.y = bb.x - bb.y * (a/b);
	}
	return aa;
}

int64_t inverse(int64_t a,int64_t m)
{
	int64_t x;
	gcdstruct aa;
	aa = EXTENDED_EUCLID(a,m);
	return aa.x MOD;      
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	xx[1] = 1;
	xx[2] = 1;
	yy[1] = 2;
	yy[2] = 4;
	int n;
	cin >> n;
	for(int i = 3 ; i <= n ; i++)
	{
		xx[i] = (xx[i - 1] MOD + xx[i - 2] MOD) MOD;
		yy[i] = yy[i - 1] * 2 MOD;
	}
	int64_t ans = (xx[n] MOD * inverse(yy[n], 998244353) MOD) MOD;
	if(ans < 0)
		ans += 998244353;
	cout << ans << "\n";
}