#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[105],aa[105],b[105],n;

bool ok(int x[],int y[])
{
    for(int i = 0;i < n;i++)
    {
        if(x[i] != y[i])    return 0;
    }
    return 1;
}

void printff(int x[])
{
    printf("%d",x[0]);
    for(int i = 1;i < n;i++)   printf(" %d",x[i]);
    printf("\n");
}

void percdown(int arr[],int p,int n)//调整最大堆
{
    int Parent,Child,x = arr[p];
    for(Parent = p;Parent*2+1 < n;Parent = Child)
	{
        Child = Parent*2+1;
        if(Child != n-1 && arr[Child] < arr[Child+1])	Child++;
        if(x >= arr[Child])	break;
        else	arr[Parent] = arr[Child];
    }
    arr[Parent] = x;
}

int main()
{
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        scanf("%d",&a[i]);
        aa[i] = a[i];
    }
    for(int i = 0;i < n;i++)   scanf("%d",&b[i]);
    int flag = 0;
    for(int i = 2;i <= n;i++)
    {
        sort(a,a+i);
        if(ok(a,b))
        {
            sort(a,a+i+1);
            printf("Insertion Sort\n");
            printff(a);
            return 0;
        }
    }
    for(int i = n/2-1;i >= 0;i--)	percdown(aa,i,n);
	for(int i = n-1;i > 0;i--)
	{
		swap(aa[0],aa[i]);
		percdown(aa,0,i);
		if(ok(aa,b))
        {
            swap(aa[0],aa[i-1]);
            percdown(aa,0,i-1);
            printf("Heap Sort\n");
            printff(aa);
            return 0;
        }
	}
}
