#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,a[50005],b[50005],cnt = 0;

void mergee(int *a,int *b,int l,int mid,int r)
{
    int i = l,j = mid+1,t = l;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j])    b[t++] = a[i++];
        else
        {
            b[t++] = a[j++];
            cnt += mid-i+1;
        }
    }
    while(i <= mid) b[t++] = a[i++];
    while(j <= r)   b[t++] = a[j++];
}
void mergesort(int *a,int *b,int l,int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        mergesort(b,a,l,mid);
        mergesort(b,a,mid+1,r);
        mergee(a,b,l,mid,r);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    mergesort(a,b,1,n);
    printf("%d\n",cnt);
    return 0;
}
