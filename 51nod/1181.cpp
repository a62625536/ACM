#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

bool a[1000500] = {0};
int n;

int main()
{
    scanf("%d",&n);
    int cnt = 1;
    for(int i = 3;;i +=2)
    {
        if(a[i])    continue;
        cnt++;
        if(n == 2 || cnt%2 && !a[cnt] && i >= n)
        {
            printf("%d\n",i);
            break;
        }
        if(1000500/i <= i)  continue;
        for(int j = i*i;j < 1000500;j += 2*i)   a[j] = 1;
    }
    return 0;
}
