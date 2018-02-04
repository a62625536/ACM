#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,a[50005],b[50005] = {0};

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    b[1] = a[1];
    int len = 1;
    for(int i = 2;i <= n;i++)
    {
        int t = lower_bound(b+1,b+len+1,a[i])-b;
        b[t] = a[i];
        if(t == len+1)  len++;
    }
    printf("%d\n",len);
    return 0;
}
