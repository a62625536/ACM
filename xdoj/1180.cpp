#include<bits/stdc++.h>
#define MOD 23333
using namespace std;

long long n,m,k;
struct matrix
{
    long long m[105][105];
};

matrix one = {0},base = {0};

matrix mul(matrix a, matrix b)
{
    matrix tmp;
    for(int i = 0; i < k-1;i++)
    {
        for(int j = 0; j < k-1;j++)
        {
            tmp.m[i][j] = 0;
            for(int K = 0;K < k-1;K++)   tmp.m[i][j] = (tmp.m[i][j]+a.m[i][K]*b.m[K][j])%MOD;
        }
    }
    return tmp;
}

long long fast_mod(long long n)
{
    matrix ans = one,y = base;
    while(n)
    {
        if(n&1) ans = mul(ans,y);
        y = mul(y,y);
        n /= 2;
    }
    long long res = 0;
    for(int i = 0;i < k-1;i++)  res = (res+ans.m[i][0])%MOD;
    return res*m%MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    for(int i = 0;i < 100;i++)  one.m[i][i] = 1;
    for(int i = 1;i < 100;i++)  base.m[i][i-1] = 1;
    while(cin >> n >> m >> k)
    {
        for(int i = 0;i < k-1;i++)    base.m[0][i] = m-1;
        cout << fast_mod(n-1) << endl;
    }
    return 0;
}
