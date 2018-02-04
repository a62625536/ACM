#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int a,b;

int main()
{
    double x = (sqrt(5)+1)/2;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&a,&b);
        if(a > b)   swap(a,b);
        int t = (b-a)*x;
        if(a == t)  printf("B\n");
        else    printf("A\n");
    }
     return 0;
}
