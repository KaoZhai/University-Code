#include <bits/stdc++.h>

using namespace std;
void mul(int A[][2], int B[][2])
{
    int C[2][2];
    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
    for(int i = 0 ; i < 2 ; i++)
        for(int j = 0 ; j < 2 ; j++)
            A[i][j] = C[i][j];
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[2][2] = {5,3,3,2};
    int b[2][2] = {1,4,8,7};
    mul(a, b);
    for(int i = 0 ; i < 2; i++)
        for(int j = 0 ; j < 2 ; j++)
            cout << a[i][j] << " ";
    cout << endl;
}
