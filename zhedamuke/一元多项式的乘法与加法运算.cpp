#include<cstdio>
#include<iostream>
#include<list>
using namespace std;

struct shu{
    int num,pow;
};
list<shu> q[2],ans[2];
list<shu>::iterator it1,it2,it;

void scanff(int which,int n)
{
    while(n--)
    {
        shu temp;
        scanf("%d%d",&temp.num,&temp.pow);
        q[which].push_back(temp);
    }
}

void insertt(int which,int num,int pow)
{
    for(it = ans[which].begin();it != ans[which].end() && pow < it->pow;it++);
    if(it != ans[which].end() && pow == it->pow)    it->num += num;
    else
    {
        shu temp;
        temp.num = num;
        temp.pow = pow;
        ans[which].insert(it,temp);
    }
}

void printff(int which)
{
    for(it = ans[which].begin();it != ans[which].end();)
    {
        if(it->num == 0)    ans[which].erase(it++);
        else    it++;
    }
    if(ans[which].empty())    printf("0 0\n");
    else
    {
        int flag = 1;
        for(it = ans[which].begin();it != ans[which].end();it++)
        {
            if(flag)
            {
                printf("%d %d",it->num,it->pow);
                flag = 0;
            }
            else    printf(" %d %d",it->num,it->pow);
        }
        putchar('\n');
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    scanff(0,n);
    scanf("%d",&n);
    scanff(1,n);
    int flag = 1;
    for(it1 = q[0].begin();it1 != q[0].end();it1++)
    {
        for(it2 = q[1].begin();it2 != q[1].end();it2++)
        {
            int num = it1->num*it2->num,pow = it1->pow+it2->pow;
            insertt(0,num,pow);
        }
    }
    it1 = q[0].begin();
    it2 = q[1].begin();
    while(it1 != q[0].end() && it2 != q[1].end())
    {
        if(it1->pow > it2->pow)
        {
            insertt(1,it1->num,it1->pow);
            it1++;
        }
        else if(it1->pow < it2->pow)
        {
            insertt(1,it2->num,it2->pow);
            it2++;
        }
        else
        {
            insertt(1,it1->num+it2->num,it1->pow);
            it2++;
            it1++;
        }
    }
    while(it1 != q[0].end())
    {
        insertt(1,it1->num,it1->pow);
        it1++;
    }
    while(it2 != q[1].end())
    {
        insertt(1,it2->num,it2->pow);
        it2++;
    }
    printff(0);
    printff(1);
    return 0;
}
