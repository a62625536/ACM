#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    stack<int> s;
    int ans = 0,now,cntover = 0;
    while(n--)
    {
        int x,y;
        cin >> x;
        if(x == 1)  cin >> now;
        else if(x == 2)
        {
            ans += cntover;
            cntover = 0;
        }
        else if(x == 3)
        {
            cin >> y;
            s.push(y);
        }
        else if(x == 4) cntover = 0;
        else if(x == 5)
        {
            while(!s.empty())   s.pop();
        }
        else    cntover++;
        while(!s.empty() && now > s.top())
        {
            ans++;
            s.pop();
        }
    }
    cout << ans << endl;
    return 0;
}
