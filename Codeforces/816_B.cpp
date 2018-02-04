#include<bits/stdc++.h>
using namespace std;

int n,k,q,a[200005] = {0},ans[200005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> q;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[x]++;
        a[y+1]--;
    }
    for(int i = 1;i <= 200000;i++)   a[i] += a[i-1];
    for(int i = 1;i <= 200000;i++)
    {
        ans[i] = ans[i-1];
        if(a[i] >= k)   ans[i]++;
    }
    while(q--)
    {
        int x,y;
        cin >> x >> y;
        cout << ans[y]-ans[x-1] << endl;
    }
    return 0;
}
