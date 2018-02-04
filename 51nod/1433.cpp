#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int cnt0 = 0,cnt5 = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x == 0)  cnt0++;
        else    cnt5++;
    }
    if(cnt5 >= 9 && cnt0)
    {
        cnt5 -= cnt5%9;
        while(cnt5--) cout << 5;
        while(cnt0--) cout << 0;
        cout << endl;
    }
    else if(cnt0)   cout << 0 << endl;
    else    cout << -1 << endl;

    return 0;
}
