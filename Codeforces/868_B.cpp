#include<bits/stdc++.h>
using namespace std;

int h,m,s,t1,t2;

int main()
{
    ios::sync_with_stdio(0);
    cin >> h >> m >> s >> t1 >> t2;
    if(t1 > t2) swap(t1,t2);
    int cnt = 0;
    if(t1 <= h && h < t2)   cnt++;
    if(5*t1 <= m && m < 5*t2)   cnt++;
    if(5*t1 < s && s < 5*t2)   cnt++;
    if(cnt == 0 || cnt == 3)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
