#include<bits/stdc++.h>
using namespace std;

int n,m,cnt[5000005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        cnt[x] = 1;
    }
    for(int i = 1;i <= 300000;i++)  cnt[i] += cnt[i-1];
    int t = 0;
    while(m--)
    {
        int z;
        cin >> z;
        t ^= z;
        int l = 0,r = (1<<19)-1;
        for(int i = 18;i >= 0;i--)
        {
            int tt = t&(1<<i),mid = (l+r)/2;
            if(tt)
            {
                if(cnt[r]-cnt[mid] < r-mid) l = mid+1;
                else    r = mid;
            }
            else
            {
                if(cnt[mid]-(l?cnt[l-1]:0) < mid-l+1)  r = mid;
                else    l = mid+1;
            }
        }
        cout << (l^t) << endl;
    }
    return 0;
}
