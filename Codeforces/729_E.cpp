#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,s,num[200005] = {0};

int main()
{
    int ans = 0,t = 0;
    scanf("%d%d",&n,&s);
    for(int i = 1;i <= n;i++)
    {
        int x;
        scanf("%d",&x);
        if(i == s && x != 0)    ans++;
        else if(i != s && x == 0)
        {
            t++;
            ans++;
        }
        else    num[x]++;
    }
    int sum = 1;
    for(int i = 1;i < n;i++)
    {
        if(sum >= n)    break;
        if(!num[i])
        {
            if(t)   t--;
            else    ans++;
            sum++;
        }
        else    sum += num[i];
    }
    printf("%d\n",ans);
    return 0;
}
