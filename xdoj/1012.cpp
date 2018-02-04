#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int nextt[400005];
char s[400005];

void get_next(int len)
{
    int i = 0,j = -1;
    nextt[0] = -1;
    while(i < len)
    {
        if(j == -1 || s[len-i-1] == s[len-j-1])	nextt[++i] = ++j;
        else    j = nextt[j];
    }
}
int main ()
{
    while(~scanf("%s",s))
    {
        int endd = strlen(s);
        get_next(endd);
        int maxlen = 0,maxcnt = 0;
        for(int i = 1;i <= endd;i++)
        {
         	int len = i-nextt[i];
            if(len && i%len == 0)
            {
                int cnt = i/len;
                if(cnt >= maxcnt)
                {
                 	maxcnt = cnt;
                 	maxlen = len;
				}
            }
        }
        if(maxcnt > 1)
        {
        	for(int i = endd-maxlen;i < endd;i++)	printf("%c",s[i]);
        	printf(" %d\n",maxcnt);
		}
        else	printf("-1\n");
    }
    return 0;
} 
