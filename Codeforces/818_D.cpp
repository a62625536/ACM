#include<bits/stdc++.h>
using namespace std;

int n,c,a[1000005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> c;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(a[x] >= a[c])   a[x]++;
    }
    for(int i = 1;i <= 1000000;i++)
    {
        if(a[i] >= a[c] && i != c)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
