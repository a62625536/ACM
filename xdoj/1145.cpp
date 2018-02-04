#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define MOD 1000000007
using namespace std;

long long l,r,anss[5] = {1,2,3,6,11};
struct matrix
{
    long long m[4][4];
};
matrix ans = {  1,0,0,0,
                0,1,0,0,
                0,0,1,0,
                0,0,0,1,};
matrix base = { 1,1,1,0,
                1,0,0,0,
                0,1,0,0,
                1,0,0,1,};

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

long long fast_mod(long long n)
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
    return (x.m[3][0]+x.m[3][1]+x.m[3][2]+2*x.m[3][3])%MOD;
}

int main()
{
    while(~scanf("%lld%lld",&l,&r))
    {
        long long x,y;
        if(l == 0)  x = 0;
        else    x = l < 6?anss[l-1]:fast_mod(l-2);
        y = r < 5?anss[r]:fast_mod(r-1);
        printf("%lld\n",(y-x+MOD)%MOD);
    }
    return 0;
}
