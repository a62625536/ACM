#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

int x1,x2,x3,x4,y1,y2,y3,y4,z1,z2,z3,z4;

bool f()
{
    int a11 = x1-x2,a12 = x2-x3,a13 = x3-x4;
    int a21 = y1-y2,a22 = y2-y3,a23 = y3-y4;
    int a31 = z1-z2,a32 = z2-z3,a33 = z3-z4;
    if(a11*a22*a33+a12*a23*a31+a13*a21*a32-a13*a22*a31-a11*a23*a32-a12*a21*a33 == 0)    return 1;
    else    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d%d%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2,&x3,&y3,&z3,&x4,&y4,&z4);
        if(f()) printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
