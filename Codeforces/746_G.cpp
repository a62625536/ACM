#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,t,k,a[200005];

int main()
{
    cin >> n >> t >> k;
    int maxx = 1-t;
    for(int i = 1;i <= t;i++)
    {
        cin >> a[i];
        maxx += a[i];
    }
    int minn = a[t];
    for(int i = 2;i <= t;i++)
    {
        minn += a[i] < a[i-1]?a[i-1]-a[i]:0;
    }
    if(minn > k || k > maxx)
    {
        cout << -1 << endl;
        return 0;
    }
    cout << n << endl;
    for(int i = 1;i <= a[1];i++)    cout << 1 << " " << i+1 << endl;
    int now = a[1]+2,last = 2,cnt = maxx-k;
    for(int i = 2;i <= t;i++)
    {
        int t = now,tt = now+a[i],lastt = last+1;
        cout << last << " " << now++ << endl;
        while(cnt && now < tt && lastt < t)
        {
            cout << lastt++ << " " << now++ << endl;
            cnt--;
        }
        while(now < tt) cout << last << " " << now++ << endl;
        last = t;
    }
    return 0;
}
