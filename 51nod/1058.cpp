#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#define PI atan(1)*4
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    printf("%d\n",(int)((0.5*log(2*PI*n)+n*log(n)-n)/log(10))+1);
    return 0;
}
