#include<bits/stdc++.h>
using namespace std;

int n;
struct xx
{
    int x,y,id;
    friend bool operator<(xx a,xx b)
    {
        return a.x < b.x;
    }
}a[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].id = i;
    }
    sort(a+1,a+1+n);
    double maxx = -1e9;
    vector<int> ans;
    for(int i = 2;i <= n;i++)
    {
        double t = (a[i].y-a[i-1].y)/(a[i].x-a[i-1].x);
        if(t > maxx)
        {
            maxx = t;
            ans.clear();
            ans.push_back(i);
        }
        else if(t == maxx)  ans.push_back(i);
    }
    for(int i = 0;i < ans.size();i++)   cout << a[ans[i]-1].id << " " << a[ans[i]].id << endl;
    return 0;
}
