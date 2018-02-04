#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

int n,k,a[200005];
vector<int> v;
priority_queue< int,vector<int>,greater<int> > q;

int main()
{
    cin >> n >> k;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i] < 0)    v.push_back(i);
    }
    if(v.size() > k)
    {
        cout << -1 << endl;
        return 0;
    }
    if(v.size() == 0)
    {
        cout << 0 <<endl;
        return 0;
    }
    for(int i = 1;i < v.size();i++) q.push(v[i]-v[i-1]-1);
    int cnt = k-v.size(),ans = 2*v.size();
    while(!q.empty())
    {
        if(cnt < q.top())   break;
        cnt -= q.top();
        ans -= 2;
        q.pop();
    }
    if(cnt >= n-v.back())   ans--;
    cout << ans << endl;
    return 0;
}
