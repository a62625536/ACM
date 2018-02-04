#include<bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int flag = 0;
    for(int i = 1;i <= m;i++)
    {
        mp.clear();
        int x,f = 0;
        cin >> x;
        while(x--)
        {
            int xx;
            cin >> xx;
            if(mp.count(-xx))   f = 1;
            mp[xx] = 1;
        }
    if(f == 0)  flag = 1;
    }
    if(flag)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
