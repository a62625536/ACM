#include<bits/stdc++.h>
using namespace std;

int n,a[200005],l[200005],r[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int last = -1e9;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] == 0)   last = i;
        l[i] = i-last;
    }
    last = 1e9;
    for(int i = n;i >= 1;i--)
    {
        if(a[i] == 0)   last = i;
        r[i] = last-i;
    }
    for(int i = 1;i <= n;i++)   cout << min(l[i],r[i]) << " ";
    cout << endl;
    return 0;
}
