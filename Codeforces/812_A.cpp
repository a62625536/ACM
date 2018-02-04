#include<bits/stdc++.h>
using namespace std;

int a[4],b[4],c[4],d[4];

int main()
{
    ios::sync_with_stdio(0);
    for(int i = 0;i < 4;i++)    cin >> a[i] >> b[i] >> c[i] >> d[i];
    int flag = 0;
    for(int i = 0;i < 4;i++)
    {
        if(!d[i])   continue;
        if(a[i] || b[i] || c[i] || a[(i+1)%4] || b[(i+2)%4] || c[(i+3)%4])  flag = 1;
    }
    if(flag)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
