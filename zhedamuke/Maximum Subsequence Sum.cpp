#include<cstdio>
#include<iostream>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin >> n;
    for(int i = 1;i <=n;i++)    cin >> a[i];
    int sum = 0,now = 0,left = 0,right = 0,templeft = a[1],flag = 1;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] >= 0)   flag = 0;
        now += a[i];
        if(now > sum)
        {
            sum = now;
            left = templeft;
            right = a[i];
        }
        else if(now < 0)
        {
            now = 0;
            templeft = a[i+1];
        }
    }
    if(sum == 0 && flag)
    {
        cout << 0 << ' ' << a[1] << ' ' << a[n] << endl;
    }
    else
    {
        cout << sum << ' ' << left << ' ' << right << endl;
    }
    return 0;
}
