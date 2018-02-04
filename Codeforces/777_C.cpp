#include<bits/stdc++.h>
using namespace std;

int n,m,k,ans[100005],last[100005] = {0},p[100005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        ans[i] = i;
        for(int j = 1;j <= m;j++)
        {
            int x;
            cin >> x;
            if(x < last[j]) p[j] = i;
            last[j] = x;
            ans[i] = min(ans[i],p[j]);
        }
    }
    cin >> k;
    while(k--)
    {
        int l,r;
        cin >> l >> r;
        if(ans[r] <= l) cout << "Yes" << endl;
        else    cout << "No" << endl;
    }
    return 0;
}
