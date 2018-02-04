#include<bits/stdc++.h>
using namespace std;

int n;
priority_queue<int,vector<int>,greater<int> > q;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        q.push(x);
    }
    int ans = 0;
    while(--n)
    {
        int x = q.top();
        q.pop();
        int y = q.top();
        q.pop();
        ans += x+y;
        q.push(x+y);
    }
    cout << ans << endl;
    return 0;
}
