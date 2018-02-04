#include<bits/stdc++.h>
using namespace std;

int n,k,a[1005][2005];
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k >> s;
    memset(a,-1,sizeof(a));
    a[0][n] = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = n-k+1;j <= n+k-1;j++)
        {
            if(a[i][j] == -1)   continue;
            if(s[i] == '?' || s[i] == 'W')  a[i+1][j+1] = j;
            if(s[i] == '?' || s[i] == 'L')  a[i+1][j-1] = j;
            if(s[i] == '?' || s[i] == 'D')  a[i+1][j] = j;
        }
    }
    if(a[n][n-k] == -1 && a[n][n+k] == -1)
    {
        cout << "NO" << endl;
        return 0;
    }
    int now = n-k;
    if(a[n][n-k] == -1)   now = n+k;
    for(int i = n;i >= 1;i--)
    {
        if(a[i][now] == now-1)  s[i-1] = 'W';
        else if(a[i][now] == now+1) s[i-1] = 'L';
        else    s[i-1] = 'D';
        now = a[i][now];
    }
    cout << s << endl;
    return 0;
}
