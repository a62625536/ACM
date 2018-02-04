#include<bits/stdc++.h>
using namespace std;

int n;
long long ans[2005];
struct xx
{
    int u,v,w;
    xx(int a,int b,int c):u(a),v(b),w(c){};
    friend bool operator <(xx a,xx b)
    {
        return a.w < b.w;
    }
};

vector<xx> v;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   ans[i] = 1e18;
    for(int i = 1;i <= n;i++)
    {
        for(int j = i+1;j <= n;j++)
        {
            int x;
            cin >> x;
            v.push_back(xx(i,j,x));
        }
    }
    sort(v.begin(),v.end());
    long long minn = v[0].w;
    for(int i = 0;i < v.size();i++)
    {
        int x = v[i].u,y = v[i].v,w = v[i].w;
        long long t = (long long)w*2+minn*(n-3);
        ans[x] = min(ans[x],min(ans[y]-minn+w,t));
        ans[y] = min(ans[y],min(ans[x]-minn+w,t));
    }
    for(int i = 1;i <= n;i++)   cout << ans[i] << endl;
    return 0;
}
