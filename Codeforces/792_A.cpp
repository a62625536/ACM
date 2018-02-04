#include<bits/stdc++.h>
using namespace std;

int n,a[200005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    int minn = 2e9+5,cnt = 0;
    for(int i = 2;i <= n;i++)
    {
        int t = a[i]-a[i-1];
        if(t == minn)   cnt++;
        else if(t < minn)
        {
            minn = t;
            cnt = 1;
        }
    }
    cout << minn << " " << cnt << endl;
    return 0;
}
