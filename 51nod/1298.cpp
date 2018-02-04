#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;

double XX,YY,R,X1,X2,X3,Y1,Y2,Y3;

bool f()
{
    double a1 = (X1-XX)*(X1-XX)+(Y1-YY)*(Y1-YY);
    double a2 = (X2-XX)*(X2-XX)+(Y2-YY)*(Y2-YY);
    double a3 = (X3-XX)*(X3-XX)+(Y3-YY)*(Y3-YY);
    double rr = R*R;
    if(a1 < rr-1e-6 && a2 < rr-1e-6 && a3 < rr-1e-6)    return 1;
    if(a1 > rr+1e-6 && a2 > rr+1e-6 && a3 > rr+1e-6)
    {
        double t = ((XX-X1)*(X2-X1)+(YY-Y1)*(Y2-Y1))*((XX-X2)*(X1-X2)+(YY-Y2)*(Y1-Y2));
        if(t > 1e-6)
        {
            t = abs((X1-XX)*(Y2-YY)-(X2-XX)*(Y1-YY))/sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
            if(t*t < rr+1e-6)   return 0;
        }
        t = ((XX-X3)*(X2-X3)+(YY-Y3)*(Y2-Y3))*((XX-X2)*(X3-X2)+(YY-Y2)*(Y3-Y2));
        if(t > 1e-6)
        {
            t = abs((X3-XX)*(Y2-YY)-(X2-XX)*(Y3-YY))/sqrt((X3-X2)*(X3-X2)+(Y3-Y2)*(Y3-Y2));
            if(t*t < rr+1e-6)   return 0;
        }
        t = ((XX-X3)*(X1-X3)+(YY-Y3)*(Y1-Y3))*((XX-X1)*(X3-X1)+(YY-Y1)*(Y3-Y1));
        if(t > 1e-6)
        {
            t = abs((X3-XX)*(Y1-YY)-(X1-XX)*(Y3-YY))/sqrt((X3-X1)*(X3-X1)+(Y3-Y1)*(Y3-Y1));
            if(t*t < rr+1e-6)   return 0;
        }
        return 1;
    }
    return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf",&XX,&YY,&R,&X1,&Y1,&X2,&Y2,&X3,&Y3);
        if(f()) printf("No\n");
        else    printf("Yes\n");
    }
    return 0;
}
