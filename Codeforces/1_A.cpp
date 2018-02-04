#include<bits/stdc++.h>
using namespace std;

int n,m,a;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> a;
    long long t = n/a;
    if(n%a) t++;
    long long tt = m/a;
    if(m%a) tt++;
    cout << t*tt << endl;
    return 0;
}
