#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue< long long,vector<long long>,greater<long long> > q;
int n,k;

int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        while(!q.empty())   q.pop();
        long long x,ans = 0;
        for(int i = 1;i <= n;i++)
        {
            scanf("%lld",&x);
            q.push(x);
        }
        while((n-1)%(k-1))
        {
            q.push(0);
            n++;
        }
        while(q.size() != 1)
        {
            long long t = 0,sum = 0;
            while(t++ < k)
            {
                sum += q.top();
                q.pop();
            }
            ans += sum;
            q.push(sum);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
