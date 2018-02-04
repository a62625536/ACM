#include<bits/stdc++.h>
using namespace std;

int n,m;
string s[105],ss[105];

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> s[i];
        s[i] = ' '+s[i];
    }
    int flag = 0;
    if(n%3 == 0)
    {
        int t1 = n/3+1,t2 = n/3*2+1;
        char a = s[1][1],b = s[t1][1],c = s[t2][1];
        if(a != b && b != c && a != c)
        {
            int ok = 1;
            for(int i = 1;i < t1;i++)
            {
                for(int j = 1;j <= m;j++)
                {
                    if(s[i][j] != a)    ok = 0;
                }
            }
            for(int i = t1;i < t2;i++)
            {
                for(int j = 1;j <= m;j++)
                {
                    if(s[i][j] != b)    ok = 0;
                }
            }
            for(int i = t2;i <= n;i++)
            {
                for(int j = 1;j <= m;j++)
                {
                    if(s[i][j] != c)    ok = 0;
                }
            }
            if(ok)  flag = 1;
        }
    }
    if(m%3 == 0)
    {
        int t1 = m/3+1,t2 = m/3*2+1;
        char a = s[1][1],b = s[1][t1],c = s[1][t2];
        if(a != b && b != c && a != c)
        {
            int ok = 1;
            for(int i = 1;i < t1;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    if(s[j][i] != a)    ok = 0;
                }
            }
            for(int i = t1;i < t2;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    if(s[j][i] != b)    ok = 0;
                }
            }
            for(int i = t2;i <= m;i++)
            {
                for(int j = 1;j <= n;j++)
                {
                    if(s[j][i] != c)    ok = 0;
                }
            }
            if(ok)  flag = 1;
        }
    }
    if(flag)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
