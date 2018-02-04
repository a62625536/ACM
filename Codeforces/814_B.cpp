#include<bits/stdc++.h>
using namespace std;

int n,a[1005],b[1005],c[1005],ok[1005] = {0},x[3];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)   cin >> b[i];
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == b[i])    ok[a[i]] = 1;
        else    x[++cnt] = i;
    }
    if(cnt == 1)
    {
        for(int i = 1;i <= n;i++)
        {
            if(!ok[i])  a[x[1]] = i;
        }
    }
    else
    {
        for(int i = 1;i <= n;i++)   c[i] = a[i];
        for(int i = 1;i <= n;i++)
        {
            if(!ok[i])
            {
                a[x[1]] = i;
                ok[i] = 1;
                break;
            }
        }
        for(int i = 1;i <= n;i++)
        {
            if(!ok[i])  a[x[2]] = i;
        }
        int cnt1 = 0,cnt2 = 0;
        for(int i = 1;i <= n;i++)
        {
            if(a[i] != b[i])    cnt1++;
            if(a[i] != c[i])    cnt2++;
        }
        if(cnt1 != 1 || cnt2 != 1)  swap(a[x[1]],a[x[2]]);
    }
    for(int i = 1;i <= n;i++)   cout << a[i] << " ";
    return 0;
}
