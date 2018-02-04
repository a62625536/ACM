#include<bits/stdc++.h>
using namespace std;

int n,m,b[1005];
long long a[1005];

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        long long x,y,z;
        cin >> x >> y >> z;
        a[y] = x;
        b[y] = z;
    }
    cin >> m;
    for(int i = 1;i <= m;i++)
    {
        int x;
        cin >> x;
        cout << a[x] << " " << b[x] << endl;
    }
    return 0;
}
