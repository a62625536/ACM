#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int a,b,c;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c);
        int x = (a+b-c)/2,y = (a+c-b)/2,z = (b+c-a)/2;
        if((x+y+z)*2==(a+b+c)&&1<=x&&x<=100000&&1<=y&&y<=100000&&1<=z&&z<=100000)    printf("%d %d %d\n",x,y,z);
        else    printf("Impossible\n");
    }
    return 0;
}
