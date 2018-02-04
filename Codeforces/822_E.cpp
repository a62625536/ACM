#include<bits/stdc++.h>
using namespace std;

string s,t;
int n,m,x,a[35],b[35];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> s >> m >> t >> x;
    s = ' '+s;
    t = ' '+t;
    for(int i = 1;i <= x;i++)   a[i] = 1;
    for(int i = 1;i <= n;i++)
    {
        for(int j = x;j >= 1;j--)
        {
            int now = a[j];
            if(i < b[j]) continue;
            int k = 0;
            while(k+now <= m)
            {
                if(s[i+k] != t[now+k])  break;
                k++;
            }
            if(now+k > m)
            {
                cout << "YES" << endl;
                return 0;
            }
            if(a[j+1] < now+k)
            {
                a[j+1] = now+k;
                b[j+1] = i+k;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}
