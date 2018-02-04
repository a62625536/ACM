#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if(a == 0 && b == 0)
    {
        puts("NO");
        return 0;
    }
    if(abs(a-b) <= 1)   puts("YES");
    else    puts("NO");
    return 0;
}
