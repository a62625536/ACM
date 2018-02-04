#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<algorithm>
using namespace std;

map<char,int> a;
map<long long,int> ok,mp;
priority_queue<int, vector<int>, greater<int> > q;
priority_queue<long long, vector<long long>, greater<long long> > q2;
map<long long,int>::iterator it;


int main()
{
    int n,temp;
    char s[5];
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%s%d",s,&temp);
        a[s[0]] = temp;
        q.push(temp);
    }
    int ans = 0;
    for(int i = 1;i < n;i++)
    {
        int a = q.top();
        q.pop();
        int b = q.top();
        q.pop();
        ans += a+b;
        q.push(a+b);
    }
    int T;
    scanf("%d",&T);
    while(T--)
    {
        mp.clear();
        while(!q2.empty())  q2.pop();
        int flag = 1;
        char ss[70];
        for(int i = 1;i <= n;i++)
        {
            scanf("%s%s",s,ss);
            long long x = 1;
            for(int i = 0;ss[i] != 0;i++)   x = x*2+ss[i]-'0';
            mp[x] = a[s[0]];
            q2.push(x);
        }
        int ans1 = 0;
        for(it = mp.end(),it--;it !=mp.begin();it--)
        {
            if(it->first == 0)   break;
            ans1 += it->second;
            mp[it->first/2] += it->second;
        }
        if(ans != ans1) flag = 0;
        if(flag)
        {
            ok.clear();
            while(flag && !q2.empty())
            {
                if(ok.count(q2.top()) == 0)
                {
                    ok[q2.top()*2] = 1;
                    ok[q2.top()*2+1] = 1;
                    q2.pop();
                }
                else    flag = 0;
            }
        }
        if(flag)    printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
