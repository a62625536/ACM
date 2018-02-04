#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int s;

int main()
{
    scanf("%d",&s);
    int x = sqrt(s+0.1);
    int y = x;
    while(x*y != s)
    {
        if(x*y < s) y++;
        else    x--;
    }
    printf("%d\n",2*(x+y));
    return 0;
}
