#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int p,a;

int main()
{
    scanf("%d%d",&p,&a);
    int flag = 0;
    for(int i = 0;i <= p;i++)
    {
        if((long long)i*i%p == a)
        {
            printf("%d ",i);
            flag = 1;
        }
    }
    if(!flag)    printf("No Solution\n");
    else    printf("\n");
    return 0;
}
