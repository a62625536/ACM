#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[15],b[15],x,y;

void e_gcd(int a,int b,int &x,int &y)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return;
    }
    e_gcd(b,a%b,x,y);
    int temp = x;
    x = y;
    y = temp-a/b*y;
}

long long chinese()
{
    long long ans = 0,m = 1;
    for(int i = 1;i <= n;i++)   m *= a[i];
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        long long mm = m/a[i];
        e_gcd(mm,a[i],x,y);
        ans = (ans+mm*x*b[i])%m;
    }
    if(ans < 0) ans += m;
    return ans;
}

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d%d",&a[i],&b[i]);
    printf("%lld\n",chinese());
    return 0;
}
