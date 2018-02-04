#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;

char a[1005],b[1005];

void mul()
{
    int x[1005],y[1005],z[2005] = {0};
    int len1 = strlen(a),len2 = strlen(b);
    for(int i = 0;i < len1;i++) x[i] = a[len1-i-1]-'0';
    for(int i = 0;i < len2;i++) y[i] = b[len2-i-1]-'0';
    for(int i = 0;i < len1;i++)
    {
        for(int j = 0;j < len2;j++) z[i+j] += x[i]*y[j];
    }
    int len = len1+len2,flag = 0;
    for(int i = 0;i < len;i++)
    {
        z[i+1] += z[i]/10;
        z[i] %= 10;
        if(z[i])    flag = i;
    }
    for(int i = flag;i >= 0;i--)    printf("%d",z[i]);
    printf("\n");
}
int main()
{
     scanf("%s%s",a,b);
     mul();
     return 0;
}
