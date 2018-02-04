#include<bits/stdc++.h>
using namespace std;

int n;
string a,b;
bool vis[200005];
int num[200005];

bool ok(int x)
{
    memset(vis,0,sizeof(vis));
    for(int i = 1;i <= x;i++)   vis[num[i]-1] = 1;
    int j = 0;
    for(int i = 0;i < n;i++)
    {
        if(vis[i])  continue;
        if(a[i] == b[j])
        {
            j++;
            if(j == b.length()) return 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> a >> b;
    n = a.length();
    for(int i = 1;i <= n;i++)   cin >> num[i];
    int l = 0,r = n;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(ok(mid)) l = mid;
        else    r = mid-1;
    }
    cout << l << endl;
    return 0;
}
