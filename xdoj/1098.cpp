#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int euler(int n)
{
    int res = n,a = n;  
    for(int i = 2;i*i <= a;i++)
	{  
        if(a%i == 0)
		{  
            res = res/i*(i-1);
            while(a%i == 0)	a /= i;  
        }  
     }  
     if(a > 1)	res = res/a*(a-1);  
     return res;  
} 

int main()
{
	int n;
	while(~scanf("%d",&n))	printf("%d\n",euler(n));
	return 0;
}
