#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int flag = 0;
    int endd = sqrt(n/2+0.1);
    for(int i = 0;i <= endd;i++)
    {
        int j = sqrt(n-i*i+0.1);
        if(i*i+j*j == n)
        {
            flag = 1;
            printf("%d %d\n",i,j);
        }
    }
    if(!flag)   printf("No Solution\n");
    return 0;
}
