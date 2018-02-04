#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a1,a2,b1,b2,c1,c2;

int main()
{
    scanf("%d%d%d%d%d%d",&a1,&a2,&b1,&b2,&c1,&c2);
    printf("3\n");
    printf("%d %d\n",a1-b1+c1,a2-b2+c2);
    printf("%d %d\n",b1-c1+a1,b2-c2+a2);
    printf("%d %d\n",c1-a1+b1,c2-a2+b2);
    return 0;
}
