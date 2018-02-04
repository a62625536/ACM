#include<bits/stdc++.h>
using namespace std;

int n,m,a[1005],ok[100005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int sum = 0;
    for(int i = 1;i <= n;i++)   cin >> a[i],sum += a[i];
    cin >> m;
    for(int i = 1;i <= m;i++)
    {
        int x,y;
        cin >> x >>y;
        for(int j = x;j <= y;j++)   ok[j] = 1;
    }
    for(int i = sum;i <= 100000;i++)
    {
        if(ok[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
