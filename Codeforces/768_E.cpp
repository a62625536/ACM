#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[25];

int main()
{
    a[0] = 0;
    for(int i = 1;i < 20;i++)   a[i] = a[i-1]+i;
    cin >> n;
    int sg = 0;
    while(n--)
    {
        int x;
        cin >> x;
        int t = lower_bound(a,a+20,x)-a;
        if(a[t] == x)   sg ^= t;
        else sg ^= t-1;
    }
    if(sg)  cout << "NO" << endl;
    else    cout << "YES" << endl;
    return 0;
}
