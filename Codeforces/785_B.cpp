#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int maxx1 = 0,minn1 = 1e9,maxx2 = 0,minn2 = 1e9;
    for(int i = 1;i <= n;i++)
    {
        int l,r;
        cin >> l >> r;
        maxx1 = max(maxx1,l);
        minn1 = min(minn1,r);
    }
    cin >> m;
    for(int i = 1;i <= m;i++)
    {
        int l,r;
        cin >> l >> r;
        maxx2 = max(maxx2,l);
        minn2 = min(minn2,r);
    }
    int ans = 0;
    if(maxx2 > minn1)   ans = max(ans,maxx2-minn1);
    if(maxx1 > minn2)   ans = max(ans,maxx1-minn2);
    cout << ans << endl;
    return 0;
}
