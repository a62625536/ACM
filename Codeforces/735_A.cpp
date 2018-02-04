#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k;
char s[105];

int main()
{
    scanf("%d%d%s",&n,&k,s);
    int a,b;
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        if(s[i] == 'G') a = i;
        else if(s[i] == 'T') b = i;
    }
    int t = a-b;
    if(t < 0)   t = -t;
    if(t%k)
    {
        printf("NO");
        return 0;
    }
    int x = a < b?a:b,endd = x+t,flag = 0;
    while(x < endd)
    {
        x += k;
        if(s[k] == '#')
        {
            flag = 1;
            break;
        }
    }
    if(flag)    printf("NO\n");
    else    printf("YES\n");
    return 0;
}
