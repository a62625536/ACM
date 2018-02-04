#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    while(~scanf("%d",&n))
    {
        if(n%3) printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
