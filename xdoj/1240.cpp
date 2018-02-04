#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

int main()
{
    while(~scanf("%d",&n))
    {
        multiset<int> s;
        for(int i = 1;i <= n;i++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int ans = 0;
        for(int i = 1;i <= n;i++)
        {
            auto it = s.lower_bound(a[i]);
            if(it != s.begin())
            {
                it--;
                ans++;
                s.erase(it);
            }
        }
        if(ans) printf("%d\n",ans);
        else    printf("Godv too strong\n");
    }
    return 0;
}
