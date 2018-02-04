#include<bits/stdc++.h>
using namespace std;

int n,m,a[1005];
map<int,int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        int t = i;
        while(t > 1 && a[t] < a[t/2])
        {
            swap(a[t],a[t/2]);
            t /= 2;
        }
    }
    for(int i = 1;i <= n;i++)   mp[a[i]] = i;
    while(m--)
    {
        int a,b;
        string s;
        cin >> a >> s;
        if(s == "and")
        {
            cin >> b >> s;
            cin >> s;
            if(mp[a]%2 == 0 && mp[b]-mp[a] == 1 || mp[a]%2 && mp[a]-mp[b] == 1) cout << "T" << endl;
            else    cout << "F" << endl;
        }
        else
        {
            cin >> s;
            if(s == "a")
            {
                cin >> s;
                cin >> s;
                cin >> b;
                if(mp[a]/2 == mp[b])   cout << "T" << endl;
                else    cout << "F" << endl;
            }
            else
            {
                cin >> s;
                if(s == "root")
                {
                    if(mp[a] == 1) cout << "T" << endl;
                    else    cout << "F" << endl;
                }
                else
                {
                    cin >> s;
                    cin >> b;
                    if(mp[a] == mp[b]/2)  cout << "T" << endl;
                    else    cout << "F" << endl;
                }
            }
        }
    }
    return 0;
}
