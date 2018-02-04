#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[1005][8];
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    int flag = 1;
    for(int i = 1;i <= n;i++)
    {
        gets(a[i]);
        if(flag)
        {
            if(a[i][0] == 'O' && a[i][1] == 'O')
            {
                flag = 0;
                a[i][0] = '+';
                a[i][1] = '+';
            }
            else if(a[i][3] == 'O' && a[i][4] == 'O')
            {
                flag = 0;
                a[i][3] = '+';
                a[i][4] = '+';
            }
        }
    }
    if(!flag)
    {
        printf("YES\n");
        for(int i = 1;i <= n;i++)   puts(a[i]);
    }
    else        printf("NO\n");
    return 0;
}
