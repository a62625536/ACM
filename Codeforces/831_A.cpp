#include<bits/stdc++.h>
using namespace std;

int n,a[105] = {0};

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    int t = 1;
    while(a[t] > a[t-1])    t++;
    while(a[t] == a[t-1])   t++;
    while(a[t] < a[t-1])    t++;
    if(t > n)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
