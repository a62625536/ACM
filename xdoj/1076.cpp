#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

LL three[40] = {0},sum[40] = {0};

int change(char x)
{
    switch(x)
    {
        case '1':   return 1;
        case '3':   return 2;
        case '5':   return 3;
    }
}

int main()
{
    three[0] = 1;
    for(int i = 1;i <= 36;i++)  three[i] = three[i-1]*3;
    for(int i = 1;i <= 36;i++)
    sum[i] = sum[i-1]+three[i];
    char s[40];
    while(~scanf("%s",s))
    {
        int len = strlen(s);
        LL ans = sum[len-1];
        for(int i = 0;i < len;i++)
        {
            ans += (change(s[i])-1)*three[len-i-1];
        }
        printf("%lld\n",ans+1);
    }
    return 0;
}
