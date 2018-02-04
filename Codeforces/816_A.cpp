#include<bits/stdc++.h>
using namespace std;

int a,b;
char c;

int f(int x)
{
    return x%10*10+x/10;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> a >> c >> b;
    int ans = 0;
    while(1)
    {
        if(f(a) == b)   break;
        ans++;
        b++;
        if(b == 60)
        {
            b = 0;
            a++;
        }
        if(a == 24) a = 0;
    }
    cout << ans << endl;
    return 0;
}
