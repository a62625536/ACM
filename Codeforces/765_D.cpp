#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,f[100005],g[100005] = {0},h[100005];

int main()
{
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++)   cin >> f[i];
    for(int i = 1;i <= n;i++)
    {
        if(f[i] == i)
        {
            cnt++;
            g[i] = cnt;
            h[cnt] = i;
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(!g[f[i]])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << cnt << endl;
    for(int i = 1;i <= n;i++)   cout << g[f[i]] << " ";
    cout << endl;
    for(int i = 1;i <= cnt;i++) cout << h[i] << " ";
    cout << endl;
    return 0;
}
