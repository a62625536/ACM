#include<bits/stdc++.h>
using namespace std;

int n;
struct xx
{
    int a,b,h;
}a[100005];
stack<xx> s;

bool cmp(xx x,xx y)
{
    if(x.b != y.b)  return x.b > y.b;
    return x.a > y.a;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i].a >> a[i].b >> a[i].h;
    sort(a+1,a+1+n,cmp);
    long long ans = 0,sum = 0;
    for(int i = 1;i <= n;i++)
    {
        while(!s.empty() && s.top().a >= a[i].b)
        {
            sum -= s.top().h;
            s.pop();
        }
        sum += a[i].h;
        s.push(a[i]);
        ans = max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
