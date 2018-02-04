#include<bits/stdc++.h>
using namespace std;

int n,c,d;
int maxdp1[100005][20],maxdp2[100005][20];
struct xx
{
    int b,x;
    xx(){};
    xx(int bb,int xx):b(bb),x(xx){};
    friend bool operator <(xx a,xx b)
    {
         return a.x < b.x;
    }
}a[100005],b[100005];

void rmq_init1(int len)
{
    for(int i = 1;i <= len;i++) maxdp1[i][0] = a[i].b;
    for(int j = 1;(1<<j) <= len;j++)
    {
        for(int i = 1;i+(1<<j)-1 <= len;i++)
        {
            maxdp1[i][j] = max(maxdp1[i][j-1],maxdp1[i+(1<<(j-1))][j-1]);
        }
    }
}

void rmq_init2(int len)
{
    for(int i = 1;i <= len;i++) maxdp2[i][0] = b[i].b;
    for(int j = 1;(1<<j) <= len;j++)
    {
        for(int i = 1;i+(1<<j)-1 <= len;i++)
        {
            maxdp2[i][j] = max(maxdp2[i][j-1],maxdp2[i+(1<<(j-1))][j-1]);
        }
    }
}

int rmq_max1(int l,int r)
{
    int k = (int)(log((double)(r-l+1))/log(2.0));
    return max(maxdp1[l][k],maxdp1[r-(1<<k)+1][k]);
}

int rmq_max2(int l,int r)
{
    int k = (int)(log((double)(r-l+1))/log(2.0));
    return max(maxdp2[l][k],maxdp2[r-(1<<k)+1][k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> c >> d;
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x,y;
        string s;
        cin >> x >> y >> s;
        if(s == "C")
        {
            a[++cnt1].b = x;
            a[cnt1].x = y;
        }
        else
        {
            b[++cnt2].b = x;
            b[cnt2].x = y;
        }
    }
    int maxx = 0;
    int pos1 = -1,max1 = 0;
    for(int i = 1;i <= cnt1;i++)
    {
        if(a[i].x <= c && a[i].b > max1)
        {
            pos1 = i;
            max1 = a[i].b;
        }
    }
    int pos2 = -1,max2 = 0;
    for(int i = 1;i <= cnt2;i++)
    {
        if(b[i].x <= d && b[i].b > max2)
        {
            pos2 = i;
            max2 = b[i].b;
        }
    }
    if(pos1 != -1 && pos2 != -1)    maxx = max1+max2;
    sort(a+1,a+1+cnt1);
    sort(b+1,b+1+cnt2);
    rmq_init1(cnt1);
    rmq_init2(cnt2);
    if(cnt1 > 1 && a[1].x+a[2].x <= c)
    {
        for(int i = 1;i <= cnt1;i++)
        {
            if(a[i].x >= c)  break;
            int t = upper_bound(a+1,a+cnt1+1,xx(0,c-a[i].x))-a-1;
            if(t <= i)  break;
            maxx = max(maxx,a[i].b+rmq_max1(i+1,t));
        }
    }
    if(cnt2 > 1 && b[1].x+b[2].x <= d)
    {
        for(int i = 1;i <= cnt2;i++)
        {
            if(b[i].x >= d)  break;
            int t = upper_bound(b+1,b+cnt2+1,xx(0,d-b[i].x))-b-1;
            if(t <= i)  break;
            maxx = max(maxx,b[i].b+rmq_max2(i+1,t));
        }
    }
    cout << maxx << endl;
    return 0;
}
