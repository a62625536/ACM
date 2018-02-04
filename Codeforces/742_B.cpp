#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,x,a[100005],cnt[100005] = {0};

int main()
{
    cin >> n >> x;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    long long ans = 0;
    for(int i = 1;i <= n;i++)
    {
        int t = a[i]^x;
        if(t > 100000)  continue;
        if(t == a[i])   ans += cnt[t]-1;
        else    ans += cnt[t];
    }
    cout << ans/2 << endl;
    return 0;
}
