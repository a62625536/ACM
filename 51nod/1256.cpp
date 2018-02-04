#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

int n,m,x,y;

int e_gcd(int a,int b)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    int ans = e_gcd(b,a%b),temp = x;
    x = y;
    y = temp-a/b*y;
    return ans;
}

int inv(int a,int mod)
{
    int gcd = e_gcd(a,mod);
    if(gcd != 1)    return -1;
    return (x%mod+mod)%mod;
}

int main()
{
    scanf("%d%d",&n,&m);
    printf("%d\n",inv(n,m));
    return 0;
}
