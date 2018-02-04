#include<bits/stdc++.h>
using namespace std;

int n;
stack<long long> s;
long long a[50005];

int main()
{
    cin >> n;
    long long ans = 0;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    a[n+1] = 0;
    for(int i = 1;i <= n+1;i++)
    {
        while(!s.empty() && a[s.top()] > a[i])
        {
            int temp = s.top();
            s.pop();
            int len = s.empty()?i-1:i-s.top()-1;
            ans = max(ans,len*a[temp]);
        }
        s.push(i);
    }
    cout << ans << endl;
    return 0;
}
