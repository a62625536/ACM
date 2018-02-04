#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

int n,ok[1005];
struct xx
{
    double a1,a2,a3,a4,a5;
}a[1005];

double f(int i,int j,int k)
{
    double t1 = a[k].a1-a[i].a1,t2 = a[k].a2-a[i].a2,t3 = a[k].a3-a[i].a3,t4 = a[k].a4-a[i].a4,t5 = a[k].a5-a[i].a5;
    double x1 = a[j].a1-a[i].a1,x2 = a[j].a2-a[i].a2,x3 = a[j].a3-a[i].a3,x4 = a[j].a4-a[i].a4,x5 = a[j].a5-a[i].a5;
    return acos((t1*x1+t2*x2+t3*x3+t4*x4+t5*x5)/sqrt(t1*t1+t2*t2+t3*t3+t4*t4+t5*t5)/sqrt(x1*x1+x2*x2+x3*x3+x4*x4+x5*x5));
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].a1 >> a[i].a2 >> a[i].a3 >> a[i].a4 >> a[i].a5;
        ok[i] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        if(!ok[i])   continue;
        for(int j = 1;j <= n;j++)
        {
            if(i == j)  continue;
            if(!ok[i])  break;
            for(int k = 1;k <= n;k++)
            {
                if(k == i)  continue;
                if(k == j)  continue;
                if(!ok[i])  break;
                double t1 = f(i,k,j);
                double t2 = f(k,i,j);
                double t3 = f(j,k,i);
                if(t1/PI*180 < 90-1e-6) ok[i] = 0;
                if(t2/PI*180 < 90-1e-6) ok[k] = 0;
                if(t3/PI*180 < 90-1e-6) ok[j] = 0;
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(ok[i])  cnt++;
    }
    cout << cnt << endl;
    for(int i = 1;i <= n;i++)
    {
        if(ok[i])  cout << i << endl;
    }
    return 0;
}
