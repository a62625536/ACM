#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int ans = 0;
        char a[50000],b[50000];
        while(n--)
        {
            scanf("%s",a);
            strcat(b,a);
            char *p = b,*o;
            while(o = strstr(p,"wanshen"))
            {
                p = o+7;
                ans++;
            }
            strcpy(b,p);
        }
        printf("%d\n",ans);
    }
    return 0;
}
