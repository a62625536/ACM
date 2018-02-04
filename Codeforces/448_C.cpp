#include<bits/stdc++.h>
using namespace std;

long long n,l,r,two[70],ans[70];
stack<int> s;

int main()
{
    cin >> n >> l >> r;
    if(n == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    two[0] = 1;
    for(int i = 1;i <= 55;i++)  two[i] = two[i-1]*2;
    long long t = n;
    while(n > 1)
    {
        s.push(n%2);
        n /= 2;
    }
    int cnt = 0;
    while(!s.empty())
    {
        ans[++cnt] = s.top();
        s.pop();
    }
    int anss = 0;
    for(long long i = l;i <= r;i++)
    {
        long long t = i;
        int flag = 0;
        for(int j = cnt;j >= 1;j--)
        {
            if(t == two[j])
            {
                anss += ans[j];
                flag = 1;
                break;
            }
            else if(t > two[j]) t = two[j+1]-t;
        }
        if(!flag)   anss++;
    }
    cout << anss << endl;
    return 0;
}
