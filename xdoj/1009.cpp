#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct segtree
{
	int left,right,sum;
}tree[800005];

void build(int pos,int l,int r)
{
    tree[pos].left = l;
    tree[pos].right = r;
    if(l == r)
    {
        tree[pos].sum = 1;
        return;
    }
    int mid = (l+r)/2;
    build(pos*2,l,mid);
    build(pos*2+1,mid+1,r);
    tree[pos].sum = tree[pos*2].sum+tree[pos*2+1].sum;
}

int update(int pos,int num)
{
    tree[pos].sum--;
    if(tree[pos].left == tree[pos].right)	return tree[pos].left;
    if(num <= tree[pos*2].sum)	return update(pos*2,num);
    else	return update(pos*2+1,num-tree[pos*2].sum);
}

int main()
{

    int n,m;
    while(~scanf("%d %d",&n,&m))
    {
        build(1,1,n);
        printf("%d",m);
        int now = m;
        update(1,now);
        for(int i = 2;i <= n;i++)
        {
        	now = (now+m-1)%tree[1].sum;
	        if(now == 0)	now = tree[1].sum;
	        printf(" %d",update(1,now));
        }
        cout << endl;
    }
    return 0;
}

