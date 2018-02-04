#include<bits/stdc++.h>
using namespace std;

int n,a[205];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= 2*n;i++) cin >> a[i];
    sort(a+1,a+1+n*2);
    reverse(a+1,a+1+n*2);
    if(a[n] > a[n+1])   cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
