#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int ans = 0;
    while(n--)
    {
        int x;
        scanf("%d",&x);
        ans ^= x;
    }
    if(ans) printf("A\n");
    else    printf("B\n");
    return 0;
}
