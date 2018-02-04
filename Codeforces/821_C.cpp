#include<bits/stdc++.h>
using namespace std;

int n;
stack<int> s;
string ss;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int now = 1,ans = 0;
    for(int i = 1;i <= 2*n;i++)
    {
        cin >> ss;
        if(ss == "add")
        {
            int x;
            cin >> x;
            s.push(x);
        }
        else
        {
            if(s.empty())
            {
                now++;
                continue;
            }
            if(now == s.top())
            {
                s.pop();
                now++;
            }
            else
            {
                ans++;
                now++;
                while(!s.empty())   s.pop();
            }
        }
    }
    cout << ans << endl;
    return 0;
}
