#include<bits/stdc++.h>
using namespace std;

int n,a[1005],b[1005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i] >> b[i];
    int flag1 = 0,flag2 = 0;
    for(int i = 1;i <= n;i++)
    {
        if(a[i] != b[i])    flag1 = 1;
    }
    for(int i = 1;i < n;i++)
    {
        if(a[i] < a[i+1])   flag2 = 1;
    }
    if(flag1)   cout << "rated" <<endl;
    else if(flag2)  cout << "unrated" << endl;
    else    cout << "maybe" << endl;
    return 0;
}
