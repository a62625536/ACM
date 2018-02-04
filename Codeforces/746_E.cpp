#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;

int n,m,a[200005];
map<int,int> mp1,mp2;

int main()
{
    cin >> n >> m;
    int cnt1 = 0,cnt2 = 0,x = 1,y = 2,ans = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(!mp1[a[i]])
        {
            if(a[i]&1)  cnt1++;
            else    cnt2++;
        }
        mp1[a[i]]++;
    }
    for(int i = 1;i <= n && cnt1 > n/2;i++)
    {
        if((a[i]&1) == 0)   continue;
        mp1[a[i]]--;
        if(mp1[a[i]] == 0)   cnt1--;
        while(mp1[y])    y += 2;
        if(y > m)
        {
            cout << -1 << endl;
            return 0;
        }
        a[i] = y;
        mp1[y]++;
        cnt2++;
        ans++;
    }
    for(int i = 1;i <= n && cnt2 > n/2;i++)
    {
        if(a[i]&1)  continue;
        mp1[a[i]]--;
        if(mp1[a[i]] == 0)   cnt2--;
        while(mp1[x])    x += 2;
        if(x > m)
        {
            cout << -1 << endl;
            return 0;
        }
        a[i] = x;
        mp1[x]++;
        cnt1++;
        ans++;
    }
    for(int i = 1;i <= n;i++)
    {
        if(mp2[a[i]])
        {
            if(cnt1 < n/2)
            {
                while(mp1[x])   x += 2;
                if(x > m)
                {
                    cout << -1 << endl;
                    return 0;
                }
                a[i] = x;
                mp1[x]++;
                cnt1++;
                ans++;
            }
            else
            {
                while(mp1[y])   y += 2;
                if(y > m)
                {
                    cout << -1 << endl;
                    return 0;
                }
                a[i] = y;
                mp1[y]++;
                cnt2++;
                ans++;
            }
        }
        mp2[a[i]] = 1;
    }
    cout << ans << endl;
    for(int i = 1;i <= n;i++)   cout << a[i] << " ";
    return 0;
}
