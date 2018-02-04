#include<bits/stdc++.h>
using namespace std;

int n;
struct xx
{
    int x,flag;
    friend bool operator<(xx a,xx b)
    {
        if(a.x != b.x)  return a.x < b.x;
        return a.flag < b.flag;
    }
}a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        cin >> x >> y;
        a[2*i-1].x = x-y;
        a[2*i-1].flag = 0;
        a[2*i].x = x+y;
        a[2*i].flag = 1;
    }
    int m = 2*n;
    sort(a+1,a+1+m);
    long long ans = 0,num = n;
    for(int i = 1;i <= m;i++)
    {
        if(a[i].flag == 0)  num--;
        else    ans += num;
    }
    cout << ans << endl;
    return 0;
}
