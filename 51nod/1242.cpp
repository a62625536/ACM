#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#define MOD 1000000009
using namespace std;

long long n;

struct matrix
{
    long long m[2][2];
};
matrix one = {  1,0,
                0,1 };
matrix base = { 1,1,
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

long long fast_mod(long long n)
{
    matrix ans = one,y = base;
    while(n)
    {
        if(n & 1)
        {
            ans = mul(ans,y);
        }
        y = mul(y,y);
        n >>= 1;
    }
    return ans.m[0][1];
}

int main()
{
    scanf("%lld",&n);
    printf("%lld\n",fast_mod(n));
    return 0;
}
