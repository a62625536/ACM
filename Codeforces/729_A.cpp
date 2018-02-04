#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char s[105];

int main()
{
    int flag = 0;
    scanf("%d%s",&n,s);
    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'o' && s[i+1] == 'g' && s[i+2] == 'o')
        {
            flag = 1;
            printf("***");
            i += 2;
        }
        else if(flag && s[i] == 'g' && s[i+1] == 'o')   i++;
        else
        {
            printf("%c",s[i]);
            flag = 0;
        }
    }
    printf("\n");
    return 0;
}
