#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int m,d,a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    cin >> m >> d;
    a[m] -= 7-d+1;
    int ans = a[m]/7+1;
    if(a[m]%7)  ans++;
    cout << ans << endl;
    return 0;
}
