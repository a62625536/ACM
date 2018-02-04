#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char s[100005],a[200005];
int p[200005];

void manacher(int len)
{
    int mx = 0,id;
    for(int i = 1;i < len;i++)
    {
        if(mx > i)    p[i] = min(p[2*id-i],mx-i);
        else    p[i] = 1;
        while(a[i+p[i]] == a[i-p[i]])   p[i]++;
        if(p[i]+i > mx)
        {
            mx = p[i]+i;
            id = i;
        }
    }
}
int main()
{
    scanf("%s",s);
    a[0] = '$';
    a[1] = '#';
    int len = 2;
    for(int i = 0;s[i];i++)
    {
        a[len++] = s[i];
        a[len++] = '#';
    }
    manacher(len);
    int ans = 0;
    for(int i = 0;i < len;i++)    ans = max(ans,p[i]);
    printf("%d\n",ans-1);
    return 0;
}
