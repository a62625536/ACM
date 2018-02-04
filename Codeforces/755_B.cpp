#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
#include<string>
using namespace std;

int n,m;
map<string,int> mp;

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        mp[s] =1;
    }
    int x = 0;
    for(int i = 1;i <= m;i++)
    {
        string s;
        cin >> s;
        if(mp[s])   x++;
    }
    int a = n-x,b = m-x;
    if(x&1) b--;
    if(a > b)   cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
