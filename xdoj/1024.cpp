#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
struct segtree
{
	int left,right,sum;
}tree[45];

void build(int pos,int l,int r)
{
	tree[pos].left = l;
	tree[pos].right = r;
	tree[pos].sum = 0;
	if(l < r)
	{
		int mid = (l+r)/2;
		build(pos*2,l,mid);
		build(pos*2+1,mid+1,r);
	}
}

int getsum(int pos,int l,int r)
{
	if(tree[pos].left == l && tree[pos].right == r)	return tree[pos].sum;
	int mid = (tree[pos].right+tree[pos].left)/2;
	if(r <= mid)	return getsum(pos*2,l,r);
	if(l > mid)		return getsum(pos*2+1,l,r);
	return getsum(pos*2,l,mid)+getsum(pos*2+1,mid+1,r);
}

void update(int pos,int num)
{
	tree[pos].sum++;
	if(tree[pos].left == tree[pos].right)	return;
	int mid = (tree[pos].left+tree[pos].right)/2;
	if(num <= mid)	update(pos*2,num);
	else	update(pos*2+1,num);
}

int main()
{
    ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
		build(1,0,9);
		cin >> n;
		long long ans = 0;
		int temp;
		while(n--)
		{
			cin >> temp;
			update(1,temp);
			if(temp == 9)	continue;
			ans = (ans+getsum(1,temp+1,9))%MOD;
		}
		cout << ans << endl;
	}
	return 0;
}

