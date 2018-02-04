#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef struct t
{
    struct t *left,*right;
    int h,num;
}tree,*tre;

int GetSum(tre avl)
{
    if(avl == NULL) return 0;
    else    return avl->h;
}

tre LL(tre a)
{
    tre b = a->left;
    a->left = b->right;
    b->right = a;
    a->h = max(GetSum(a->left),GetSum(a->right))+1;
    b->h = max(GetSum(b->left),GetSum(b->right))+1;
    return b;
}

tre RR(tre a)
{
    tre b = a->right;
    a->right = b->left;
    b->left = a;
    a->h = max(GetSum(a->left),GetSum(a->right))+1;
    b->h = max(GetSum(b->left),GetSum(b->right))+1;
    return b;
}
tre LR(tre a)
{
    a->left = RR(a->left);
    a = LL(a);
    return a;
}

tre RL(tre a)
{
    a->right = LL(a->right);
    a = RR(a);
    return a;
}

tre insertt(tre avl,int v)
{
    if(avl == NULL)
    {
        avl = new tree;
        avl->left = NULL;
        avl->right = NULL;
        avl->num = v;
        avl->h = 0;
    }
    else if(avl->num > v)
    {
        avl->left = insertt(avl->left,v);
        if(GetSum(avl->left)-GetSum(avl->right) >= 2)
        {
            if(avl->left->num < v)  avl = LR(avl);
            else                    avl = LL(avl);
        }
    }
    else if(avl->num < v)
    {
        avl->right = insertt(avl->right,v);
        if(GetSum(avl->right)-GetSum(avl->left) >= 2)
        {
            if(avl->right->num < v) avl = RR(avl);
            else                    avl = RL(avl);
        }
    }
    avl->h = max(GetSum(avl->left),GetSum(avl->right))+1;
    return avl;
}

int main()
{
    int n;
    scanf("%d",&n);
    tre avl = NULL;
    for(int i = 1;i <= n;i++)
    {
        int v;
        scanf("%d",&v);
        avl = insertt(avl,v);
    }
    printf("%d\n",avl->num);
}
