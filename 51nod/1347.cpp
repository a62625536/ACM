#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char s[1000005];

int main()
{
    scanf("%s",s);
    int len = strlen(s);
    if(len%2)
    {
        printf("NO\n");
        return 0;
    }
    int flag = 0;
    for(int i = 0;i < len/2;i++)
    {
        if(s[i] != s[i+len/2])
        {
            flag = 1;
            break;
        }
    }
    if(flag)    printf("NO\n");
    else    printf("YES\n");
    return 0;
}
