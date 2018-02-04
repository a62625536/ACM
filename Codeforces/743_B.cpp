#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
long long k;

void f(int n,long long a,long long b)
{
    if(a/2+1 == b)
    {
        printf("%d\n",n);
        return;
    }
    if(b <= a/2)    f(n-1,a/2,b);
    else    f(n-1,a/2,a-b+1);
}

int main()
{
    cin >> n >> k;
    long long t = 1;
    for(int i = 1;i < n;i++)    t = t*2+1;
    f(n,t,k);
    return 0;
}
