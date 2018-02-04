#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char s[105];

int main()
{
    int cnt = 0;
    char now = 'a';
    scanf("%s",s);
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        if(now <= s[i])	cnt += min(s[i]-now,now+26-s[i]);
        else	cnt += min(now-s[i],s[i]+26-now);
        now = s[i];
    }
    printf("%d\n",cnt);
    return 0;
}

