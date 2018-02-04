#include<bits/stdc++.h>
using namespace std;

int n,a[1<<20+5] = {0};

void add(int now,int x)
{
    if(a[now] == 0) a[now] = x;
    else
    {
        if(x < a[now])  add(now*2+1,x);
        else    add(now*2,x);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        add(1,x);
    }
    int endd = 1<<n,flag = 0;
    cout << a[1];
    for(int i = 2;i < endd;i++)
    {
        if(a[i])    cout << " " << a[i];
        else if(i <= n) flag = 1;
    }
    cout << endl;
    if(flag)    cout << "NO" << endl;
    else    cout << "YES" << endl;
    return 0;
}
