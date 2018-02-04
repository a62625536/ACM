#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int cnt = 0;
    while(n <= m)
    {
        n *= 3;
        m *= 2;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
