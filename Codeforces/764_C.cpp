#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,x[100005],y[100005],c[100005],a[100005] = {0};

int main()
{
    scanf("%d",&n);
    for(int i = 1;i < n;i++)    scanf("%d%d",&x[i],&y[i]);
    for(int i = 1;i <= n;i++)   scanf("%d",&c[i]);
    int cnt = 0;
    for(int i = 1;i < n;i++)
    {
        if(c[x[i]] != c[y[i]])
        {
            cnt++;
            a[x[i]]++;
            a[y[i]]++;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == cnt)
        {
            printf("YES\n%d\n",i);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
