#include<iostream>
#include<cstdio>
using namespace std;

typedef struct node
{
    int num,flag;
    struct node *left,*right;
}List;

int n,l;

List* insertt(List *now,int x)
{
    if(now == NULL)
    {
        now = new List;
        now->num = x;
        now->flag = 0;
        now->left = NULL;
        now->right = NULL;
    }
    else if(x > now->num)    now->right = insertt(now->right,x);
    else    now->left = insertt(now->left,x);
    return now;
}

int findd(List *now,int x)
{
   if(now->flag)
   {
       if(x > now->num) findd(now->right,x);
       else if(x < now->num)  findd(now->left,x);
       else return 0;
   }
   else
   {
       if(x == now->num)
       {
           now->flag = 1;
           return 1;
       }
       else return 0;
   }
}

void initflag(List *now)
{
    now->flag = 0;
    if(now->left)   initflag(now->left);
    if(now->right)  initflag(now->right);
}

void freee(List *now)
{
    if(now->left)   freee(now->left);
    if(now->right)  freee(now->right);
    delete now;
}

int main()
{
    while(~scanf("%d",&n) && n)
    {
        scanf("%d",&l);
        List *T = new List;
        scanf("%d",&(T->num));
        T->flag = 0;
        T->left = NULL;
        T->right = NULL;
        for(int i = 2;i <= n;i++)
        {
            int temp;
            scanf("%d",&temp);
            insertt(T,temp);
        }
        while(l--)
        {
            int temp,flag = 1;
            scanf("%d",&temp);
            if(temp == T->num)  T->flag = 1;
            else    flag = 0;
            for(int i = 2;i <= n;i++)
            {
                scanf("%d",&temp);
                if(flag && !findd(T,temp))  flag = 0;
            }
            if(flag)    printf("Yes\n");
            else    printf("No\n");
            initflag(T);
        }
        freee(T);
    }
    return 0;
}
