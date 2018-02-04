#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a,b,k,ans[200005];
char s[200005];

int main()
{
    scanf("%d%d%d%d%s",&n,&a,&b,&k,s);
    int t = 0,cnt = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == '1') t = 0;
        else    t++;
        if(t == b)
        {
            ans[++cnt] = i+1;
            t = 0;
        }
    }
    cnt -= a-1;
    printf("%d\n",cnt);
    for(int i = 1;i <= cnt;i++) printf("%d ",ans[i]);
    printf("\n");
    return 0;
}
