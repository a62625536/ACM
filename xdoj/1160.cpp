#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;

int n,m;
struct ss
{
    int num,t,o;
}a[1000005];
set<int> s;

bool cmp(ss x,ss y)
{
    return x.t < y.t;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++)   scanf("%d%d%d",&a[i].o,&a[i].t,&a[i].num);
    sort(a+1,a+1+n,cmp);
    int cnt = 1;
    for(int i = 1;i <= m;i++)
    {
        int p,q;
        scanf("%d%d",&p,&q);
        while(cnt <= n&& a[cnt].t < p)
        {
            if(a[cnt].o == 1)   s.insert(a[cnt].num);
            else    s.erase(a[cnt].num);
            cnt++;
        }
        if(s.count(q))  printf("YES\n");
        else    printf("NO\n");
    }
    return 0;
}
