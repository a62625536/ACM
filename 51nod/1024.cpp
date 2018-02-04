#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
using namespace std;

set<double> s;
int n,m,a,b;

int main()
{
    scanf("%d%d%d%d",&m,&n,&a,&b);
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)    s.insert((b+j)*log2((a+i)));
    }
    printf("%d\n",s.size());
    return 0;
}
