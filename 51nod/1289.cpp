#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

stack<int> s;
int n;

int main()
{
    scanf("%d",&n);
    int ans = n;
    while(n--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(b)   s.push(a);
        else
        {
            while(!s.empty() && s.top() < a)
            {
                ans--;
                s.pop();
            }
            if(!s.empty())  ans--;
        }
    }
    printf("%d\n",ans);
    return 0;
}
