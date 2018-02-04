#include<bits/stdc++.h>
using namespace std;

int n,x,y;


int ask(vector<int> v)
{
    if(v.empty())   return 0;
    cout << "? " << v.size();
    for(int i = 0;i < v.size();i++) cout << " " << v[i];
    cout << endl;
    int x;
    cin >> x;
    return x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> x >> y;
    int diff = 0,diffb;
    for(int i = 0;i < 10;i++)
    {
        vector<int> v;
        for(int j = 1;j <= n;j++)
        {
            if(j&(1<<i))    v.push_back(j);
        }
        int t = ask(v);
        if(t == y || t == (x^y))
        {
            diff |= (1<<i);
            diffb = i;
        }
    }
    vector<int> a,b;
    for(int i = 1;i <= n;i++)
    {
        if(i&(1<<diffb))    a.push_back(i);
        else    b.push_back(i);
    }
    if(a.size() > b.size()) swap(a,b);
    int l = 0,r = a.size()-1;
    while(l < r)
    {
        int mid = (l+r)/2;
        vector<int> v;
        for(int i = l;i <= mid;i++) v.push_back(a[i]);
        int t = ask(v);
        if(t == y ||t == (x^y)) r = mid;
        else    l = mid+1;
    }
    int ans1 = a[l],ans2 = ans1^diff;
    if(ans1 > ans2) swap(ans1,ans2);
    cout << "! " << ans1 << " " << ans2 << endl;
	return 0;
}
