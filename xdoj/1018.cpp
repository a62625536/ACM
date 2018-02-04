#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
 
int n,k,t;
 
int fun(int x)
{
    int a = (n-x+k)%(n-x+1);
    for(int i = 2;i <= x;)
    {
		int temp = min(x+1-i,(n-x+i-a-1)/k+1);
		a = (a+k*temp)%(n-x+i+temp-1);
        i += temp;
    }
    return a;
}
int main()
{
   while(~scanf("%d%d%d",&n,&k,&t))
   {
       int x;
       scanf("%d",&x);
       printf("%d",fun(x)+1);
       while(--t)
       {
           scanf("%d",&x);
           printf(" %d",fun(x)+1);
       }
       printf("\n");
   }
   return 0;
}
