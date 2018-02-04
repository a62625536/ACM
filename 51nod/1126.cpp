#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#define MOD 7
using namespace std;

int a,b,n;

struct matrix
{
    long long m[2][2];
};
matrix one = {  1,0,
                0,1 };
matrix base;

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
    if(n == 1)  return 1;
    n--;
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
    return (ans.m[0][0]+ans.m[1][0]+MOD)%MOD;
}

int main()
{
    scanf("%d%d%d",&a,&b,&n);
    base.m[0][1] = b;
    base.m[1][1] = a;
    base.m[1][0] = 1;
    printf("%lld\n",fast_mod(n));
    return 0;
}
