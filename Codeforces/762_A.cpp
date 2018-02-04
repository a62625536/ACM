#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

long long n,k,a[10000005];

int main()
{
    cin >> n >> k;
    long long endd = sqrt(n),cnt = 0;
    for(int i = 1;i <= endd;i++)
    {
        if(n%i == 0)    a[++cnt] = i;
    }
    long long t = endd*endd == n?cnt-1:cnt;
    for(int i = t;i >= 1;i--)    a[++cnt] = n/a[i];
    if(cnt < k) cout << -1 << endl;
    else    cout << a[k] << endl;
    return 0;
}

