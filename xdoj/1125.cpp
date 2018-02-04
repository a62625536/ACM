#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

double f(double x1,double y1,double x2,double y2,double x3,double y3)
{
    double a,b,c,p;
    a = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    b = sqrt((x1-x3)*(x1-x3)+(y1-y3)*(y1-y3));
    c = sqrt((x3-x2)*(x3-x2)+(y3-y2)*(y3-y2));
    p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main()
{
    double x1,x2,x3,y1,y2,y3,x,y;
    while(~scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x,&y))
    {
        if(abs(f(x1,y1,x2,y2,x3,y3)-f(x,y,x2,y2,x3,y3)-f(x1,y1,x,y,x3,y3)-f(x1,y1,x2,y2,x,y)) < 1e-6)  printf("Orz\n");
        else    printf("stO\n");
    }
    return 0;
}
