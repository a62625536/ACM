#include<bits/stdc++.h>
using namespace std;

int n,m,k,a[300005],b[300005],c[2000005] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(int i = 1;i <= m;i++)
    {
        int x;
        cin >> x;
        c[x] = 1;
    }
    for(int i = 1;i <= k;i++)   cin >> a[i] >> b[i];
    if(c[1])
    {
        cout << 1 << endl;
        return 0;
    }
    int now = 1;
    for(int i = 1;i <= k;i++)
    {
        if(a[i] == now) now = b[i];
        else if(b[i] == now) now = a[i];
        if(c[now] == 1)
        {
            cout << now << endl;
            return 0;
        }
    }
    cout << now << endl;
    return 0;
}
