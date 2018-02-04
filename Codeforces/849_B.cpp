#include<bits/stdc++.h>
using namespace std;

int n,a[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int t = a[3]-a[2];
    int ok = 0;
    for(int i = 3;i <= n;i++)
    {
        if(a[i]-a[i-1] != t)    ok = 1;
    }
    if(!ok)
    {
        if(a[2]-a[1] == t)  cout << "No" << endl;
        else    cout << "Yes" << endl;
        return 0;
    }
    ok = 0;
    for(int i = 2;i <= n;i++)
    {
        double t = 1.0*(a[i]-a[1])/(i-1);
        vector<int> v;
        for(int j = 2;j <= n;j++)
        {
            if(abs(1.0*(a[j]-a[1])/(j-1)-t) > 1e-8) v.push_back(j);
        }
        int flag = 1;
        for(int j = 1;j < v.size();j++)
        {
            if(abs(1.0*(a[v[j]]-a[v[0]])/(v[j]-v[0])-t) > 1e-8)   flag = 0;
        }
        if(flag)    ok = 1;
    }
    if(ok)  cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}
