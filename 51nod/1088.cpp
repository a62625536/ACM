#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char a[1005];

int main()
{
    scanf("%s",a);
    int len = strlen(a),ans = 1;
    for(int i = 0;i < len;i++)
    {
        int l = i,r = i;
        while(a[l] == a[r+1])   r++;
        i = r;
        while(l > 0 && r < len-1 && a[l-1] == a[r+1])
        {
            l--;
            r++;
        }
        ans = max(r-l+1,ans);
    }
    printf("%d\n",ans);
    return 0;
}
