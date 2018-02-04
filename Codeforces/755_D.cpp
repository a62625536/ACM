#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
int a[1000005];

inline int lowbit(int x)
{
    return x&-x;
}

void add(int x)
{
    while(x <= n)
    {
        a[x]++;
        x += lowbit(x);
    }
}

int getsum(int x)
{
    int sum = 0;
    while(x)
    {
        sum += a[x];
        x -= lowbit(x);
    }
    return sum;
}

int main()
{
    cin >> n >> k;
    if(k > n/2) k = n-k;
    int x = 1,y;
    long long ans = 1;
    for(int i = 1;i <= n;i++)
    {
        y = x+k;
        if(y > n)   y -= n;
        if(y > x)   ans += getsum(y-1)-getsum(x)+1;
        else    ans += getsum(n)-getsum(x)+getsum(y-1)+1;
        add(x);
        add(y);
        x = y;
        cout << ans << " ";
    }
    return 0;
}
