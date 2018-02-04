#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char a[1005];

int main()
{
    while(~scanf("%s",a))
    {
        int len = strlen(a),first = 0,last = 0,now = 0;
        while(now < len)
        {
            first = last = now;
            char maxx = a[now];
            for(int i = len-1;i > now;i--)
            {
                if(a[i] > maxx)
                {
                    maxx = a[i];
                    last = i;
                }
            }
            if(first != last)   break;
            for(now++;a[now] == a[now-1];now++);
        }
        swap(a[first],a[last]);
        printf("%s\n",a);
    }
    return 0;
}

