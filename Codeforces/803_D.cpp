#include<bits/stdc++.h>
using namespace std;

int n,cnt = 1,a[1000005] = {0};
string s;

bool ok(int x)
{
    int cntt = 0,now = 0;
    for(int i = 1;i <= cnt;i++)
    {
        if(a[i] > x)  return 0;
        now += a[i];
        if(now > x)
        {
            cntt++;
            now = a[i];
        }
    }
    if(now > 0) cntt++;
    if(cntt <= n)   return 1;
    return 0;
}
int main()
{
    cin >> n;
    getchar();
    getline(cin,s);
    for(int i = 0;i < s.length();i++)
    {
        a[cnt]++;
        if(s[i] == ' ' || s[i] == '-')    cnt++;
    }
    int l = 1,r = 1e6;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(ok(mid)) r = mid;
        else    l = mid+1;
    }
    cout << l << endl;
    return 0;
}
