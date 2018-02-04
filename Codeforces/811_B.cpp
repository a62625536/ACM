#include<bits/stdc++.h>
using namespace std;

int n,m,a[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    while(m--)
    {
        int l,r,x;
        cin >> l >> r >> x;
        int cnt = 0;
        for(int i = l;i <= r;i++)   if(a[i] < a[x]) cnt++;
        if(l+cnt == x)   cout << "Yes" << endl;
        else    cout << "No" << endl;
    }
    return 0;
}
