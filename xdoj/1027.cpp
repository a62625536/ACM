#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
struct matrix
{
    long long m[2][2];
};

matrix one = {  1,0,
                0,1 };
matrix base = { 2,1,
                1,0 };

matrix mul(matrix a, matrix b)
{
    matrix tmp;
    for(int i = 0; i < 2;i++)
    {
        for(int j = 0; j < 2;j++)
        {
            tmp.m[i][j] = 0;
            for(int k = 0; k < 2;k++)   tmp.m[i][j] = (tmp.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
        }
    }
    return tmp;
}

long long fast_mod(int n)
{
    matrix ans = one,y = base;
    while(n)
    {
        if(n&1) ans = mul(ans,y);
        y = mul(y,y);
        n /= 2;
    }
    return ans.m[0][0];
}

int main()
{
    while(cin >> n) cout << fast_mod(n-1) << endl;
    return 0;
}
