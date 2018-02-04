#include<bits/stdc++.h>
using namespace std;

int n,w,h,tx[100005],ty[100005],ansx[100005],ansy[100005];
struct xx
{
    int x,t,id;
    friend bool operator<(xx a,xx b)
    {
        if(a.x-a.t != b.x-b.t)  return a.x-a.t < b.x-b.t;
        return a.x < b.x;
    }
}a[100005],b[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> w >> h;
    int cnt1 = 0,cnt2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x,y,t;
        cin >> x >> y >> t;
        if(x == 1)
        {
            a[++cnt1].x = y;
            a[cnt1].t = t;
            a[cnt1].id = i;
            tx[i] = y;
            ty[i] = h;
        }
        else
        {
            b[++cnt2].x = y;
            b[cnt2].t = t;
            b[cnt2].id = i;
            tx[i] = w;
            ty[i] = y;
        }
    }
    sort(a+1,a+1+cnt1);
    sort(b+1,b+1+cnt2);
    int now1 = 1,now2 = 1;
    while(now1 <= cnt1 && now2 <= cnt2)
    {
        if(a[now1].x-a[now1].t == b[now2].x-b[now2].t)
        {
            int t1 = now1+1,t2 = now2+1;
            while(t1 <= cnt1 && a[now1].x-a[now1].t == a[t1].x-a[t1].t) t1++;
            while(t2 <= cnt2 && b[now2].x-b[now2].t == b[t2].x-b[t2].t) t2++;
            vector<int> v1,v2;
            for(int i = now1;i < t1;i++)    v1.push_back(a[i].id);
            for(int i = t2-1;i >= now2;i--) v1.push_back(b[i].id);
            for(int i = t2-1;i >= now2;i--) v2.push_back(b[i].id);
            for(int i = now1;i < t1;i++)    v2.push_back(a[i].id);
            for(int i = 0;i < v1.size();i++)
            {
                ansx[v2[i]] = tx[v1[i]];
                ansy[v2[i]] = ty[v1[i]];
            }
            now1 = t1;
            now2 = t2;
        }
        else if(a[now1].x-a[now1].t < b[now2].x-b[now2].t)
        {
            ansx[a[now1].id] = tx[a[now1].id];
            ansy[a[now1].id] = ty[a[now1].id];
            now1++;
        }
        else
        {
            ansx[b[now2].id] = tx[b[now2].id];
            ansy[b[now2].id] = ty[b[now2].id];
            now2++;
        }
    }
    while(now1 <= cnt1)
    {
        ansx[a[now1].id] = tx[a[now1].id];
        ansy[a[now1].id] = ty[a[now1].id];
        now1++;
    }
    while(now2 <= cnt2)
    {
        ansx[b[now2].id] = tx[b[now2].id];
        ansy[b[now2].id] = ty[b[now2].id];
        now2++;
    }
    for(int i = 1;i <= n;i++)   cout << ansx[i] << " " << ansy[i] <<endl;
    return 0;
}
