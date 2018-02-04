#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,z;

int gcd(int a,int b)
{
    return b?gcd(b,a%b):a;
}

int main()
{
    scanf("%d%d%d",&n,&m,&z);
    int t = n*m/gcd(n,m);
    printf("%d\n",z/t);
    return 0;
}
