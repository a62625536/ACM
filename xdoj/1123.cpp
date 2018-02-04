#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

struct orz
{
    int id,x;
    friend bool operator<(struct orz X,struct orz Y)
    {
        if(X.x == Y.x)  return X.id < Y.id;
        return X.x < Y.x;
    }
}a[100005],t;
int n,m;

int main()
{
    t.id = 0;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i = 1;i <= n;i++)
        {
            scanf("%d",&a[i].x);
            a[i].id = i;
        }
        sort(a+1,a+1+n);
        int flag = 1;
        while(m--)
        {
            scanf("%d",&t.x);
            int ans = lower_bound(a+1,a+1+n,t)-a;
            if(flag)
            {
                if(ans > n) printf("-1");
                else    printf("%d",a[ans].id);
                flag = 0;
            }
            else
            {
                if(ans > n) printf(" -1");
                else   printf(" %d",a[ans].id);
            }
        }
        printf("\n");
    }
    return 0;
}
