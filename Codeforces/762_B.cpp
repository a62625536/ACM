#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int a,b,c,n,x[300005],y[300005];

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&n);
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int t;
        char s[20];
        scanf("%d%s",&t,s);
        if(s[0] == 'U')  x[++cnt1] = t;
        else    y[++cnt2] = t;
    }
    sort(x+1,x+1+cnt1);
    sort(y+1,y+1+cnt2);
    int now1 = 1,now2 = 1,cnt = 0;
    long long ans = 0;
    while(a && now1 <= cnt1)
    {
        cnt++;
        ans += x[now1++];
        a--;
    }
    while(b && now2 <= cnt2)
    {
        cnt++;
        ans += y[now2++];
        b--;
    }
    while(c && now1 <= cnt1 && now2 <= cnt2)
    {
        if(x[now1] < y[now2])
        {
            ans += x[now1++];
            cnt++;
        }
        else
        {
            ans += y[now2++];
            cnt++;
        }
        c--;
    }
    while(c && now1 <= cnt1)
    {
        cnt++;
        ans += x[now1++];
        c--;
    }
    while(c && now2 <= cnt2)
    {
        cnt++;
        ans += y[now2++];
        c--;
    }
    printf("%d %I64d\n",cnt,ans);
    return 0;
}
