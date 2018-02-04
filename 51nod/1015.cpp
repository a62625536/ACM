#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[5];

int f()
{
    for(int i = n;;i++)
    {
        int cnt = 0,t = i;
        while(t)
        {
            a[++cnt] = t%10;
            t /= 10;
        }
        int sum = 0;
        for(int i = 1;i <= cnt;i++)
        {
            int tt = a[i];
            for(int j = 1;j < cnt;j++)  tt *= a[i];
            sum += tt;
        }
        if(sum == i)    return i;
    }
}

int main()
{
    scanf("%d",&n);
    printf("%d\n",f());
    return 0;
}
