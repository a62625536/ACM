#include<bits/stdc++.h>
using namespace std;

int n,k,a[25];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int t = 0;t < (1<<n);t++)
    {
        int sum = 0;
        for(int i = 1;i <= n;i++)
        {
            if(t&(1<<(i-1)))    sum += a[i];
        }
        if(sum == k)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}
