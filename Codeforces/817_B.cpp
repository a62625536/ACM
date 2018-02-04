#include<bits/stdc++.h>
using namespace std;

int n,a[100005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    int num = 1,cnt = 0;
    if(a[2] != a[1])    num++;
    if(a[3] != a[2])    num++;
    if(num == 1)
    {
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == a[1])    cnt++;
        }
        cout << (long long)cnt*(cnt-1)*(cnt-2)/6 << endl;
    }
    else if(num == 2 && a[2] != a[1])
    {
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == a[2])    cnt++;
        }
        cout << (long long)cnt*(cnt-1)/2 << endl;
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            if(a[i] == a[3])    cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}
