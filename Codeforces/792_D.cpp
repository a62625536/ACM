#include<bits/stdc++.h>
using namespace std;

long long n,q,two[100];
string s;

int main()
{
    ios::sync_with_stdio(false);
    two[0] = 1;
    for(int i = 1;i <= 64;i++)  two[i] = two[i-1]*2;
    cin >> n >> q;
    int maxx = lower_bound(two,two+64,n+1)-two-1;
    while(q--)
    {
        long long x;
        cin >> x;
        int cnt = 0;
        long long t = x;
        while(t%2 == 0)
        {
            cnt++;
            t /= 2;
        }
        cin >> s;
        for(int i = 0;i < s.length();i++)
        {
            if(s[i] == 'U')
            {
                if(cnt == maxx) continue;
                long long t = x;
                while(t%2 == 0)    t /= 2;
                t /= 2;
                if(t%2)    x -= two[cnt];
                else    x += two[cnt];
                cnt++;
            }
            else if(s[i] == 'L')
            {
                if(cnt == 0)    continue;
                cnt--;
                x -= two[cnt];
            }
            else
            {
                if(cnt == 0)    continue;
                cnt--;
                x += two[cnt];
            }
        }
        cout << x << endl;
    }
    return 0;
}
