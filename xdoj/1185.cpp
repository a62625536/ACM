#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int m,k,t[100005];

bool ok(int x)
{
    int cnt = 0,sum = 0;
    for(int i = 1;i <= m;i++)
    {
        if(sum+t[i] < x)    sum += t[i];
        else if(sum+t[i] == x)
        {
            cnt++;
            sum = 0;
        }
        else
        {
            cnt++;
            sum = t[i];
        }
    }
    if(sum) cnt++;
    if(cnt > k) return 1;
    return 0;
}

int main()
{
    while(~scanf("%d%d",&m,&k))
    {
        for(int i = 1;i <= m;i++)   scanf("%d",&t[i]);
        int l = 1,r = 100000000;
        while(l < r)
        {
            int mid = (l+r)/2;
            if(ok(mid)) l = mid+1;
            else    r = mid;
        }
        printf("%d\n",l);
    }
    return 0;
}
