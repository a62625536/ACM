#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n,flag = 0;
double ansl = 0,ansr = 1e9;

void f(int x,int v,int l,int r)
{
    if(v == 0 && (x <= l || x >= r))
    {
        flag = 1;
        return;
    }
    double t = 1.0*(l-x)/v,tt = 1.0*(r-x)/v;
    ansl = max(ansl,min(t,tt));
    ansr = min(ansr,max(t,tt));
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    for(int i = 1;i <= n;i++)
    {
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        f(a,c,x1,x2);
        f(b,d,y1,y2);
    }
    if(flag == 0 && ansl < ansr)    cout << fixed << setprecision(10) << ansl << endl;
    else    cout << -1 << endl;
    return 0;
}
