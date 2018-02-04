#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[100005],n;

int f(int last)
{
    for(int i = last;i < n;i++)
    {
        if(a[i] != i)   return i;
    }
    return 0;
}
int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        int x;
        scanf("%d",&x);
        a[x] = i;
    }
    int cnt = 0,last = 1;
    while(last = f(last))
    {
        if(a[0] == 0)
        {
            swap(a[0],a[last]);
            cnt++;
        }
        else
        {
            int t = a[0];
            swap(a[0],a[t]);
            cnt++;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
