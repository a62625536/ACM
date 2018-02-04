#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int n;

int main()
{
    cin >> n;
    int now = 0;
    while(n--)
    {
        int x;
        string s;
        cin >> x >> s;
        if(now == 0 && s != "South" || now == 20000 && s != "North")
        {
            cout << "NO" << endl;
            return 0;
        }
        if(s == "South")    now += x;
        else if(s == "North")   now -= x;
        if(now < 0 || now > 20000)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    if(now == 0)  cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
