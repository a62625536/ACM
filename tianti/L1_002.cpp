#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n >> s;
    if(n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    n--;
    int now = 6;
    while(n >= now)
    {
        n -= now;
        now += 4;
    }
    now = (now-4)/2;
    for(int i = now;i >= 1;i -= 2)
    {
        int j = (now-i)/2;
        while(j--)  cout << " ";
        j = i;
        while(j--)  cout << s[0];
        cout << endl;
    }
    for(int i = 3;i <= now;i += 2)
    {
        int j = (now-i)/2;
        while(j--)  cout << " ";
        j = i;
        while(j--)  cout << s[0];
        cout << endl;
    }
    cout << n << endl;
    return 0;
}
