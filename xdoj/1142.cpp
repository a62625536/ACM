#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

char a[100005],b[100005];
int s[128];

int main()
{
    while(!scanf("%s%s",a,b))
    {
        memset(s,0,sizeof(s));
        int flag=0,lena = strlen(a),lenb = strlen(b);
        for(int i = 0;i < lenb;i++) s[b[i]] = 1;
        for(int i = 0;i < lena;i++)
        {
            if(!s[a[i]])
            {
                putchar(a[i]);
                flag = 1;
            }
        }
        if(!flag)   printf("EMPTY");
        printf("\n");
    }
    return 0;
 }
