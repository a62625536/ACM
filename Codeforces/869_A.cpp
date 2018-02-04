#include<bits/stdc++.h>
using namespace std;

int n,a[2005],b[2005],ok[4000005] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        ok[a[i]] = 1;
    }
    for(int i = 1;i <= n;i++)
    {
        cin >> b[i];
        ok[b[i]] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        for(int j = 1;j <= n;j++)   if(ok[a[i]^b[j]])   ans++;
    }
    if(ans%2)   cout << "Koyomi" << endl;
    else    cout << "Karen" << endl;
    return 0;
}
