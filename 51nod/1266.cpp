#include<bits/stdc++.h>
using namespace std;

int n,l;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> l;
    int ans1 = 0,ans2 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        ans1 = max(ans1,min(x,l-x));
        ans2 = max(ans2,max(x,l-x));
    }
    cout << ans1 << " " << ans2 << endl;
    return 0;
}
