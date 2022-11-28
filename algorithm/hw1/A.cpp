#include <bits/stdc++.h>

#define mod %1000000007

using namespace std;

int64_t A[2][2] = {0};

void mul(int64_t D[][2], int64_t B[][2])
{
	int64_t C[2][2] = {0};

	C[0][0] = ((D[0][0] mod) * (B[0][0] mod) mod + (D[0][1] mod) * (B[1][0] mod) mod)mod;
    C[0][1] = ((D[0][0] mod) * (B[0][1] mod) mod + (D[0][1] mod) * (B[1][1] mod) mod)mod;
    C[1][0] = ((D[1][0] mod) * (B[0][0] mod) mod + (D[1][1] mod) * (B[1][0] mod) mod)mod;
    C[1][1] = ((D[1][0] mod) * (B[0][1] mod) mod + (D[1][1] mod) * (B[1][1] mod) mod)mod;

     for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            D[i][j] = C[i][j];

    return;
}

void power(int64_t A[][2], int64_t n)
{


	if(n == 1)	return;

	int64_t tmp[2][2] = {0};

	for(int i = 0 ; i < 2 ; i++)
		for(int j = 0 ; j < 2 ; j++)
			tmp[i][j] = A[i][j] mod;

	power(tmp, n / 2);


	if(n & 1)
	{
		mul(tmp, tmp);
		mul(A, tmp);
		return;
	}
	else
	{
		mul(tmp, tmp);
		for(int i = 0 ; i < 2 ; i++)
			for(int j = 0 ; j < 2 ; j++)
				A[i][j] = tmp[i][j] mod;
		return;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int64_t a1, a2, x, y, n, ans;
	while(cin >> a1 >> a2 >> x >> y >> n)
	{
		A[0][0] = x mod;
		A[0][1] = y mod;
		A[1][0] = 1;
		A[1][1] = 0;

		power(A, n - 2);

		ans = (A[0][1] mod * (a1 mod) mod + A[0][0] mod * (a2 mod) mod )mod;
		cout << ans << endl;
	}
}