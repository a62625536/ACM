#include<bits/stdc++.h>
using namespace std;

int n,m,a[105],b[105];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= m;i++)   cin >> b[i];
    sort(b+1,b+1+m);
    reverse(b+1,b+1+m);
    int now = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0)   a[i] = b[++now];
    }
    for(int i = 2;i <= n;i++)
    {
        if(a[i-1] > a[i])
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}


