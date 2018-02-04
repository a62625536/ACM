#include<bits/stdc++.h>
#define LL long long
using namespace std;

int n;
LL a[105],b[105];
char c;

LL gcd(LL x,LL y)
{
    return y?gcd(y,x%y):x;
}

LL lcm(LL x,LL y)
{
    return x*y/gcd(x,y);
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i] >> c >> b[i];
        LL t = gcd(abs(a[i]),b[i]);
        a[i] /= t;
        b[i] /= t;
    }
    int x = a[1],y = b[1];
    for(int i = 2;i <= n;i++)
    {
        x = x*b[i]+y*a[i];
        y *= b[i];
        if(x)
        {
            LL t = gcd(abs(x),y);
            x /= t;
            y /= t;
        }
    }
    if(x == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    LL xx = x/y;
    x = x%y;
    if(x == 0)  cout << xx << endl;
    else if(xx == 0)    cout << x << "/" << y << endl;
    else    cout << xx << " " << x << "/" << y << endl;
    return 0;
}
