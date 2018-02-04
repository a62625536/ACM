#include<bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

long long qmod(long long a,long long b,long long c)
{
    long long ans = 1;
    a = a%c;
    while(b)
    {
        if(b%2)  ans = (ans*a)%c;
        a = (a*a)%c;
        b /= 2;
    }
    return ans;
}

long long c(long long m,long long n,long long MOD)
{
    if(m < n)   return 0;
    if(m == n)  return 1;
    if(n > m-n) n = m-n;
    long long mm = 1,nn = 1;
    for(long long i = 0;i < n;i++)
    {
        mm = mm*(m-i)%MOD;
        nn = nn*(n-i)%MOD;
    }
    return mm*qmod(nn,MOD-2,MOD)%MOD;
}

long long lucas(long long m,long long n,long long MOD)
{
    long long ans = 1;
    while(m && n && ans)
    {
        ans = ans%MOD*c(m%MOD,n%MOD,MOD)%MOD;
        n /= MOD;
        m /= MOD;
    }
    return ans;
}

long long e_gcd(long long a,long long b,long long &x,long long &y)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = e_gcd(b,a%b,y,x);
    y -= a/b*x;
    return d;
}

long long solve(long long *m,long long *a,long long n)
{
    long long M = m[1],A = a[1],x,y;
    for(int i = 2;i <= n;i++)
    {
        long long d = e_gcd(M,m[i],x,y);
        if((a[i]-A)%d)  return -1;
        x = (a[i]-A)/d*x%(m[i]/d);
        A += x*M;
        M = M/d*m[i];
        A %= M;
    }
    if(A < 0)   A += M;
    return A;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)   scanf("%lld",&a[i]);
        long long t1 = 0,t2 = 0,t3 = 0;
        for(int i = 1;i <= n;i++)
        {
            t1 = (t1+lucas(n-1,i-1,7)*a[i])%7;
            t2 = (t2+lucas(n-1,i-1,11)*a[i])%11;
            t3 = (t3+lucas(n-1,i-1,13)*a[i])%13;
        }
        long long a[4],m[4];
        a[1] = t1;
        a[2] = t2;
        a[3] = t3;
        m[1] = 7;
        m[2] = 11;
        m[3] = 13;
        printf("%lld\n",solve(m,a,3));
    }
    return 0;
}
