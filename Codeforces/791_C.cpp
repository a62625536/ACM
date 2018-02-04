#include<bits/stdc++.h>
using namespace std;

int n,k,a[55];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int cnt = 0;
    for(int i = 1;i < k;i++)    a[i] = ++cnt;
    for(int i = k;i <= n;i++)
    {
        string s;
        cin >> s;
        if(s == "YES")  a[i] = ++cnt;
        else    a[i] = a[i-k+1];
    }
    for(int i = 1;i <= n;i++)
    {
        cout << (char)(a[i]/26+'A') << (char)(a[i]%26+'a') << " ";
    }
    cout << endl;
    return 0;
}
