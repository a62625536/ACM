#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[128] = {0};
char s[10005];

int main()
{
    scanf("%s",s);
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        if(s[i] >= 'A' && s[i] <= 'Z')  s[i] = s[i]-'A'+'a';
        a[s[i]]++;
    }
    sort(a+1,a+128);
    reverse(a+1,a+128);
    int ans = 0;
    for(int i = 1;i <= 26;i++)  ans += a[i]*(26-i+1);
    printf("%d\n",ans);
    return 0;
}
