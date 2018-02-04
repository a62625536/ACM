#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,l,a[105],b[105];

int main()
{
    cin >> n >> l;
    for(int i = 0;i < n;i++)   cin >> a[i];
    for(int i = 0;i < n;i++)   cin >> b[i];
    int t1 = a[0],t2 = b[0];
    for(int i = 0;i < n-1;i++)
    {
        a[i] = a[i+1]-a[i];
        b[i] = b[i+1]-b[i];
    }
    a[n-1] = t1-a[n-1]+l;
    b[n-1] = t2-b[n-1]+l;
    for(int i = 0;i < n;i++)
    {
        int flag = 1;
        for(int j = 0;j < n;j++)
        {
            if(a[(j+i)%n] != b[j])
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
