#include<cstdio>
#include<iostream>
using namespace std;
int a[100005];
int main()
{
    int n;
    cin >> n;
    int sum = 0,now = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        now += a[i];
        if(now > sum)   sum = now;
        else if(now < 0)    now = 0;
    }
    cout << sum << endl;
    return 0;
}
