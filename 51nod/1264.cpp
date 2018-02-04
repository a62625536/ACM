#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;

double x1,x2,x3,x4,y1,y2,y3,y4;

bool f()
{
    double t1 = (x2-x1)*(y3-y2)-(x3-x2)*(y2-y1);
    double t2 = (x2-x1)*(y4-y2)-(x4-x2)*(y2-y1);
    double t3 = (x4-x3)*(y1-y4)-(x1-x4)*(y4-y3);
    double t4 = (x4-x3)*(y2-y4)-(x2-x4)*(y4-y3);
    if(t1*t2 <= 0 && t3*t4 <= 0)    return 1;
    else    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        if(f()) printf("Yes\n");
        else    printf("No\n");
    }
    return 0;
}
