#include<bits/stdc++.h>
using namespace std;

int n,a[1005];

bool ok1(int l,int r)
{
    if(l >= r)  return 1;
    int x = a[l],p = l+1;
    while(p <= r && a[p] < x)   p++;
    for(int i = p;i <= r;i++)
    {
        if(a[i] < x)    return 0;
    }
    if(ok1(l+1,p-1) && ok1(p,r))    return 1;
    return 0;
}

bool ok2(int l,int r)
{
    if(l >= r)  return 1;
    int x = a[l],p = l+1;
    while(p <= r && a[p] >= x)   p++;
    for(int i = p;i <= r;i++)
    {
        if(a[i] >= x)    return 0;
    }
    if(ok2(l+1,p-1) && ok2(p,r))    return 1;
    return 0;
}

void printf1(int l,int r)
{
    if(l > r)  return;
    int x = a[l],p = l+1;
    while(p <= r && a[p] < x)   p++;
    printf1(l+1,p-1);
    printf1(p,r);
    if(l == 1)  cout << a[l];
    else    cout << a[l] << " ";
}

void printf2(int l,int r)
{
    if(l > r)  return;
    int x = a[l],p = l+1;
    while(p <= r && a[p] >= x)   p++;
    printf2(l+1,p-1);
    printf2(p,r);
    if(l == 1)  cout << a[l];
    else    cout << a[l] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    if(ok1(1,n))
    {
        cout << "YES" << endl;
        printf1(1,n);
        cout << endl;
    }
    else if(ok2(1,n))
    {
        cout << "YES" << endl;
        printf2(1,n);
        cout << endl;
    }
    else    cout << "NO" << endl;
    return 0;
}
