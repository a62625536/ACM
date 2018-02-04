#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define MOD 1000000007
using namespace std;

int n,anss[6] = {0,0,0,1,3,7};
struct matrix
{
    long long m[4][4];
};

matrix ans = {  1,0,0,0,
                0,1,0,0,
                0,0,1,0,
                0,0,0,1,};
matrix base = { 3,1,0,0,
                MOD-2,0,1,0,
                MOD-1,0,0,1,
                1,0,0,0,};

matrix mul(matrix a, matrix b)
{
    matrix tmp;
    for(int i = 0; i < 4;i++)
    {
        for(int j = 0; j < 4;j++)
        {
            tmp.m[i][j] = 0;
            for(int k = 0; k < 4;k++)   tmp.m[i][j] = (tmp.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
        }
    }
    return tmp;
}

long long fast_mod(int n)
{
    matrix x = ans,y = base;
    while(n)
    {
        if(n & 1)
        {
            x = mul(x,y);
        }
        y = mul(y,y);
        n >>= 1;
    }
    return (anss[5]*x.m[0][0]+anss[4]*x.m[1][0]+anss[3]*x.m[2][0]+anss[2]*x.m[3][0])%MOD;
}

int main()
{
    while(~scanf("%d",&n))
    {
        if(n <= 5)  printf("%d\n",anss[n]);
        else    printf("%lld\n",fast_mod(n-5));
    }
}
