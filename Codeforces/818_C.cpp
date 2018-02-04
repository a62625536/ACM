#include<bits/stdc++.h>
using namespace std;

int d,n,m,ll,rr,tt,bb,x[100005],xx[100005],y[100005],yy[100005],l[100005] = {0},r[100005] = {0},t[100005] = {0},b[100005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> d >> n >> m;
    for(int i = 1;i <= d;i++)
    {
        cin >> x[i] >> y[i] >> xx[i] >> yy[i];
        l[min(x[i],xx[i])]++;
        r[max(x[i],xx[i])]++;
        t[min(y[i],yy[i])]++;
        b[max(y[i],yy[i])]++;
    }
    cin >> ll >> rr >> tt >> bb;
    for(int i = 1;i <= max(n,m);i++)
    {
        l[i] += l[i-1];
        t[i] += t[i-1];
    }
    for(int i = max(n,m);i >= 1;i--)
    {
        r[i] += r[i+1];
        b[i] += b[i+1];
    }
    for(int i = 1;i <= d;i++)
    {
        int cntl = l[max(x[i],xx[i])-1];
        int cntr = r[min(x[i],xx[i])+1];
        int cntt = t[max(y[i],yy[i])-1];
        int cntb = b[min(y[i],yy[i])+1];
        if(x[i] != xx[i])
        {
            cntl--;
            cntr--;
        }
        else
        {
            cntt--;
            cntb--;
        }
        if(cntl == ll && cntr == rr && cntt == tt && cntb == bb)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
