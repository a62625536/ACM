#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int a[1000005],n,q,o,t = 0,c = 0;
vector< pair<int,int> > v[1000005];
vector< pair<int,int> >::iterator it;

int lowbit(int x)
{
    return x&(-x);
}

void update(int pos,int x)
{
    while(pos <= n)
    {
        int temp = 0;
        if(!v[pos].empty()) temp = v[pos].back().second;
        v[pos].push_back(make_pair(t,temp+x));
        pos += lowbit(pos);
    }
}

int getsum(int pos,int tt)
{
    int sum = 0;
    while(pos > 0)
    {
        it = upper_bound(v[pos].begin(),v[pos].end(),make_pair(tt,0));
        if(it != v[pos].end() && it->first == tt)    sum += it->second;
        else if(it != v[pos].begin())
        {
            it--;
            sum += it->second;
        }
        pos -= lowbit(pos);
    }
    return sum;
}

int main()
{
    scanf("%d%d",&n,&q);
    while(q--)
    {
        scanf("%d",&o);
        if(o == 1)
        {
            t++;
            int i,x;
            scanf("%d%d",&i,&x);
            c = i^c;
            update(c,x);
            a[c] += x;
            c = a[c];
        }
        else
        {
            int l,r,tt;
            scanf("%d%d%d",&l,&r,&tt);
            c = getsum(r^c,tt)-getsum((l^c)-1,tt);
            printf("%d\n",c);
        }
    }
    return 0;
}
