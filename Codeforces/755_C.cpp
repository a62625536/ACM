#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,pre[10005];

int findd(int x)
{
    return x == pre[x]?x:pre[x] = findd(pre[x]);
}

int join(int a,int b)
{
    int x = findd(a),y = findd(b);
    if(x != y)  pre[x] = y;
}

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)   pre[i] = i;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        join(i,x);
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        if(pre[i] == i) ans++;
    }
    cout << ans << endl;
    return 0;
}
