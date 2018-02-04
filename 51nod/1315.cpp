#include<bits/stdc++.h>
using namespace std;

int n,x,num[50] = {0},has[50];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> x;
    int cnt = 0;
    int X = x;
    while(x)
    {
        has[++cnt] = x%2;
        x /= 2;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> x;
        if((x|X) > X)   continue;
        int t = 0;
        while(x)
        {
            num[++t] += x%2;
            x /= 2;
        }
    }
    int minn = 1e9;
    for(int i = 1;i <= cnt;i++)
    {
        if(has[i])  minn = min(minn,num[i]);

    }
    cout << minn << endl;
    return 0;
}
