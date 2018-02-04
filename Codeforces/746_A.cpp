#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a,b,c;

int main()
{
    cin >> a >> b >> c;
    b /= 2;
    c /= 4;
    int ans = min(a,b);
    ans = min(ans,c);
    cout << ans*7 << endl;
    return 0;
}
