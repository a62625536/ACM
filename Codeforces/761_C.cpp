#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int n,m,a[55],b[55],c[55];
int main()
{
    cin >> n >> m;
    memset(a,0x11,sizeof(a));
    memset(b,0x11,sizeof(b));
    memset(c,0x11,sizeof(c));
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        for(int j = 0;j < m;j++)
        {
            if(s[j] >= 'a' && s[j] <= 'z')  a[i] = min(a[i],min(j,m-j));
            else if(s[j] >= '0' && s[j] <= '9') b[i] = min(b[i],min(j,m-j));
            else    c[i] = min(c[i],min(j,m-j));
        }
    }
    int ans = 100000;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)
        {
            for(int k = 1;k <= n;k++)
            {
                if(i == j || j == k || i == k)  continue;
                ans = min(ans,a[i]+b[j]+c[k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
