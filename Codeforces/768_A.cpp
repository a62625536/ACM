#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[100005];

int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    sort(a+1,a+1+n);
    int x,y;
    for(x = 1;x <= n && a[x] == a[1];x++);
    for(y = n;y >= 1 && a[y] == a[n];y--);
    if(x > y)   cout << 0 << endl;
    else    cout << y-x+1 << endl;
    return 0;
}
