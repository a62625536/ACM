#include<bits/stdc++.h>
#define N 200005
using namespace std;

long long z,ans;

void ok(long long x)
{
    long long endd = sqrt(x/2);
    for(long long i = 1;i <= endd;i++)
    {
        long long a = i*i,b = x-a;
        long long t = sqrt(b);
        if(t*t == b && __gcd(a,b) == 1 && a != b)   ans++;
    }
}
int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        cin >> z;
        ans = 1;
        long long endd = sqrt(2*z);
        for(long long i = 1;i <= endd;i++)
        {
            if(2*z%i)   continue;
            ok(i);
            ok(2*z/i);
        }
        cout << ans*4 << endl;
    }
    return 0;
}
