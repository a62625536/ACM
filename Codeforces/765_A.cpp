#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char s[5],a[5],b[5];

int main()
{
    scanf("%d%s",&n,s);
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        scanf("%3s->%3s",a,b);
        if(strcmp(s,a) == 0)    cnt++;
        if(strcmp(s,b) == 0)    cnt++;
    }
    if(cnt&1)   printf("contest\n");
    else    printf("home\n");
    return 0;
}
