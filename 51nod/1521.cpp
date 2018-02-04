#include<bits/stdc++.h>
using namespace std;

int n,k,x,m,a[200005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> x >> m;
    for(int i = 1;i <= m;i++)   cin >> a[i];
    set<int> s;
    s.insert(0);
    s.insert(n+1);
    int num = (n+1)/(x+1);
    for(int i = 1;i <= m;i++)
    {
        s.insert(a[i]);
        auto it = s.lower_bound(a[i]);
        it++;
        int r = *it;
        it--;it--;
        int l = *it;
        num -= (r-l)/(x+1);
        num += (a[i]-l)/(x+1);
        num += (r-a[i])/(x+1);
        if(num < k)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
