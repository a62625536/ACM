#include<iostream>
#include<cstring>
#include<cstdio>
int pre[10005],ans[10005] = {0};

int findd(int x)
{
    if(x == pre[x])   return x;
    int root = findd(pre[x]);
    pre[x] = root;
    return root;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   pre[i] = i;
    char s[5];
    while(scanf("%s",s))
    {
        if(s[0] == 'S') break;
        else if(s[0] == 'I')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int xx = findd(x),yy = findd(y);
            if(xx != yy)    pre[xx] = yy;
        }
        else if(s[0] == 'C')
        {
            int x,y;
            scanf("%d%d",&x,&y);
            int xx = findd(x),yy = findd(y);
            if(xx == yy)    printf("yes\n");
            else    printf("no\n");
        }
    }
    for(int i = 1;i <= n;i++)   ans[findd(i)] = 1;
    int num = 0;
    for(int i = 1;i <= n;i++)
    {
        if(ans[i] == 1)  num++;
    }
    if(num == 1)    printf("The network is connected.\n");
    else    printf("There are %d components.\n",num);
    return 0;
}
