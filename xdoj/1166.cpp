#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char a[200005],b[100005];
int n;

void change()
{
    for(int i = 0;i < n;i++)
    {
        if(b[i] == '3') b[i] = '1';
        else    b[i] += 1;
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        scanf("%s%s",a,b);
        for(int i = 0;i < n;i++)    a[i+n] = a[i];
        a[2*n] = 0;
        char *p;
        for(int i = 0;i < 4;i++)
        {
            char *p = strstr(a,b);
            if(p != NULL)   break;
            change();
        }
        if(p == NULL)   printf("no\n");
        else    printf("yes\n");
    }
    return 0;
}
