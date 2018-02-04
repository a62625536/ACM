#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[105];

int main()
{
    cin >> n;
    int sum = 0,flag = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum += a[i];
        if(a[i] != 0)   flag = 1;
    }
    if(!flag)   cout << "NO" << endl;
    else if(sum != 0)
    {
        cout << "YES" << endl;
        cout << 1 << endl;
        cout << 1 << " " << n << endl;
    }
    else
    {
        sum = 0;
        int x = 1;
        for(;x <= n;x++)
        {
            sum += a[x];
            if(sum != 0)    break;
        }
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << 1 << " " << x << endl;
        cout << x+1 << " " << n << endl;
    }
    return 0;
}
