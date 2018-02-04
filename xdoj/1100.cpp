#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

stack<int> s;
long long a[100005],b[100005];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        while(!s.empty())   s.pop();
        long long ans = 0;
        b[1] = 0;
        for(int i = 1;i <= n;i++)   scanf("%lld",&a[i]);
        for(int i = 2;i <= n;i++)
        {
            scanf("%lld",&b[i]);
            b[i] += b[i-1];
        }
        a[n+1] = 0;
        for(int i = 1;i <= n+1;i++)
        {
            while(!s.empty() && a[s.top()] > a[i])
            {
                int temp = s.top();
                s.pop();
                long long len = s.empty()?b[i-1]:b[i-1]-b[s.top()+1];
                ans = max(ans,len*a[temp]);
            }
            s.push(i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
