#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[55],b[55];
char s[55];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        int n = strlen(s);
        for(int i = 1;i <= n;i++)
        {
            a[i] = s[i-1]-'0';
            b[n-i+1] = a[i]^1;
        }
        int pos;
        for(pos = 1;pos <= n;pos++)
        {
            int flag = 1;
            for(int i = pos,j = 1;i <= n;i++,j++)
            {
                if(a[i] != b[j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)   break;
        }
        for(int i = 1;i < pos;i++)  printf("%d",a[i]);
        for(int i = 1;i <= n;i++)   printf("%d",b[i]);
        printf("\n");
    }
    return 0;
}
