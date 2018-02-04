#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

int x,y,n;
long long a[3][3];
char c[3][3];
int f(int x)
{
    if(x < 0)   return 0;
    if(x == 0)  return 1;
    return 2;
}

int main()
{
    memset(a,0x3f,sizeof(a));
    memset(c,0,sizeof(c));
    scanf("%d%d%d",&n,&x,&y);
    int s[2],xx,yy;
    while(n--)
    {
        scanf("%s%d%d",s,&xx,&yy);
        xx -= x;
        yy -= y;
        if(xx != 0 && yy != 0 && abs(xx) != abs(yy))    continue;
        if(a[f(xx)][f(yy)] > max(abs(xx),abs(yy)))
        {
            a[f(xx)][f(yy)] = max(abs(xx),abs(yy));
            c[f(xx)][f(yy)] = s[0];
        }
    }
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 3;j++)
        {
            if(c[i][j] == 'Q')
            {
                printf("YES\n");
                return 0;
            }
            if(c[i][j] == 'B' && (i+j)%2 == 0)
            {
                printf("YES\n");
                return 0;
            }
            if(c[i][j] == 'R' &&(i+j)%2)
            {
                printf("YES\n");
                return 0;
            }
        }
    }
    printf("NO\n");
    return 0;
}
