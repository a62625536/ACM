#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a,b;
char s[100005];

int main()
{
    scanf("%d%d%d%s",&n,&a,&b,s+1);
    if(s[a] != s[b])    printf("1\n");
    else    printf("0\n");
    return 0;
}
