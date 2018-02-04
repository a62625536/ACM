#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    int ans = 0;
    for(int i = 1;n/i;i *= 10)
    {
        int t = n/i%10,a = n/(i*10),b = n%i;
        if(t > 1)   ans += (a+1)*i;
        else if(t == 1) ans += a*i+b+1;
        else    ans += a*i;

    }
    printf("%d\n",ans);
    return 0;
}
