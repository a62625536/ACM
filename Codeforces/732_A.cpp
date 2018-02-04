#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int k,r;

int main()
{
    scanf("%d%dd",&k,&r);
    for(int i = 1;i <= 10;i++)
    {
        int t = i*k;
        if(t%10 == 0 || (t-r)%10 == 0)
        {
            printf("%d\n",i);
            return 0;
        }
    }
}
