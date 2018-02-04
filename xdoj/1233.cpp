#include<bits/stdc++.h>
using namespace std;

int n,a[100005],b[100005],mp[100005];

int main()
{
    ios::sync_with_stdio(0);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
        for(int i = 1;i <= n;i++)   scanf("%d",&b[i]);
        for(int i = 1;i <= n;i++)   mp[b[i]] = i;
        for(int i = 1;i <= n;i++)   a[i] = mp[a[i]];
        b[1] = a[1];
        int len = 1;
        for(int i = 2;i <= n;i++)
        {
            int t = lower_bound(b+1,b+len+1,a[i])-b;
            b[t] = a[i];
            if(t == len+1)  len++;
        }
        printf("%d\n",len);

    }
    return 0;
}
