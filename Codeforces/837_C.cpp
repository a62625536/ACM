#include<bits/stdc++.h>
using namespace std;

int n,a,b,x[105],y[105];

bool ok(int i,int j)
{
    if(x[i]+y[j] <= a && max(y[i],x[j]) <= b)    return 1;
    if(x[i]+y[j] <= b && max(y[i],x[j]) <= a)    return 1;
    if(x[i]+x[j] <= a && max(y[i],y[j]) <= b)    return 1;
    if(x[i]+x[j] <= b && max(y[i],y[j]) <= a)    return 1;
    if(y[i]+y[j] <= b && max(x[i],x[j]) <= a)    return 1;
    if(y[i]+y[j] <= a && max(x[i],x[j]) <= b)    return 1;
    if(y[i]+x[j] <= b && max(x[i],y[j]) <= a)    return 1;
    if(y[i]+x[j] <= a && max(x[i],y[j]) <= b)    return 1;
    return 0;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    for(int i = 1;i <= n;i++)   cin >> x[i] >> y[i];
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            if(ok(i,j)) ans = max(ans,x[i]*y[i]+x[j]*y[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
