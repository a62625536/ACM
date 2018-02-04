#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        ans++;
        n -= i;
    }
    cout << ans << endl;
    n += ans;
    for(int i = 1;i < ans;i++)  cout << i << " ";
    cout << n << endl;
    return 0;
}
