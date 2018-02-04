#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int cnt = 0;
    for(int i = 2;i*i <= n;i++)
    {
        if(n%i) continue;
        cnt++;
        int t = 0;
        while(n%i == 0)
        {
            n /= i;
            t++;
        }
        if(t >= 2)
        {
            printf("0\n");
            return 0;
        }
        if(t == 0)  cnt++;
    }
    if(n != 1)  cnt++;
    if(cnt%2)   printf("-1\n");
    else    printf("1\n");
    return 0;
}
