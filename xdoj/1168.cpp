#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char a[100005];
int x[30],y[30];

int main()
{
    int T;
    scanf("%d",&T);
    for(int c = 1;c <= T;c++)
    {
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        scanf("%s",a);
        int len = strlen(a);
        for(int i = 0;i < len;i++)
        {
            if('a' <= a[i] && a[i] <= 'z')  x[a[i]-'a']++;
            else    y[a[i]-'A']++;
        }
        sort(x,x+26);
        sort(y,y+26);
        printf("Case %d: %d\n",c,min(x[0],y[0]));
    }
    return 0;
}
