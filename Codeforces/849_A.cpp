#include<bits/stdc++.h>
using namespace std;

int n,a[105];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    if(a[1]%2 && a[n]%2 && n%2)    cout << "Yes" << endl;
    else    cout << "No" << endl;
    return 0;
}
