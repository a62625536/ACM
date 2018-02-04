#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

long long n;
int dp[100];

int main()
{
    cin >> n;
    long long ans = -1,a = 1,b = 1;
    while(n >= a)
    {
        ans++;
        long long t = a;
        a += b;
        b = t;
    }
    cout << ans << endl;
    return 0;
}
