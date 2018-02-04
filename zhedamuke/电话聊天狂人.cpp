#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

map<long long,int> mp;
int n;

int main()
{
    scanf("%d",&n);
    n *= 2;
    long long t,ansnum = 0;
    int ans = 0,num = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%lld",&t);
        if(mp.count(t)) mp[t]++;
        else    mp[t] = 1;
        if(mp[t] == ans && t < ansnum)
        {
            ansnum = t;
            num++;
        }
        else if(mp[t] == ans)   num++;
        else if(mp[t] > ans)
        {
            ans = mp[t];
            ansnum = t;
            num = 1;
        }
    }
    if(num == 1)    printf("%lld %d\n",ansnum,ans);
    else    printf("%lld %d %d\n",ansnum,ans,num);
    return 0;
}
