#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

long long qmod(long long a,long long b,long long c)
{
    long long ans = 1;
    a = a%c;
    while(b)
    {
        if(b&1) ans = ans*a%c;
        b >>= 1;
        a = a*a%c;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << qmod(1378,n,10) << endl;
    return 0;
}
