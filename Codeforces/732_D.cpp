#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,d[100005],a[100005],ok[100005];

int f(int x)
{
    memset(ok,0,sizeof(ok));
    long long sum = 0;
    for(int i = x;i >= 1;i--)
    {
        if(d[i] && !ok[d[i]])
        {
            ok[d[i]] = 1;
            sum += a[d[i]];
        }
        else if(sum)    sum--;
    }
    for(int i = 1;i <= m;i++)
    {
        if(!ok[i])  return 0;
    }
    if(sum) return 0;
    return 1;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)   scanf("%d",&d[i]);
    for(int i = 1;i <= m;i++)   scanf("%d",&a[i]);
    int l = 1,r = n;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(f(mid))  r = mid;
        else    l = mid+1;
    }
    if(f(l))    printf("%d\n",l);
    else    printf("-1\n");
    return 0;
}
