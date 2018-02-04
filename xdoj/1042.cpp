#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

priority_queue<double,vector<double>,greater<double> > q;
int n;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i = 1;i <= n;i++)
        {
            double temp;
            scanf("%lf",&temp);
            q.push(temp);
        }
        for(int i = 1;i < n;i++)
        {
            double a = q.top();
            q.pop();
            double b = q.top();
            q.pop();
            q.push((a+b)/2);
        }
        printf("%.2f\n",q.top()+0.00001);
        q.pop();
    }
    return 0;
}
