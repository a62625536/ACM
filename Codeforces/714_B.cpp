#include<bits/stdc++.h>
using namespace std;

int n,a[100005];
map<int,int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(!mp.count(x))
        {
            cnt++;
            mp[x] = 1;
            a[cnt] = x;
        }
    }
    if(cnt == 1 || cnt == 2)    cout << "YES" << endl;
    else if(cnt >= 4)   cout << "NO" << endl;
    else
    {
        sort(a+1,a+4);
        if(a[1]+a[3] == 2*a[2]) cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}

