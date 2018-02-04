#include<bits/stdc++.h>
using namespace std;

string s;
int q,tree[4][11][11][100005] = {0};
map<char,int> mp;

inline int lowbit(int x)
{
    return x&-x;
}

void add(int x,int y,int z,int pos,int xx)
{
    while(pos < s.length())
    {
        tree[x][y][z][pos] += xx;
        pos += lowbit(pos);
    }
}

int getsum(int x,int y,int z,int pos)
{
    int sum = 0;
    while(pos > 0)
    {
        sum += tree[x][y][z][pos];
        pos -= lowbit(pos);
    }
    return sum;
}

int main()
{
	ios::sync_with_stdio(0);
	cin >> s >> q;
	s = ' '+s;
	mp['A'] = 0;
	mp['G'] = 1;
	mp['C'] = 2;
	mp['T'] = 3;
	for(int i = 1;i < s.length();i++)
    {
        for(int j = 1;j <= 10;j++)  add(mp[s[i]],i%j,j,i,1);
    }
	while(q--)
    {
        int x;
        cin >> x;
        if(x == 1)
        {
            string ss;
            cin >> x >> ss;
            for(int i = 1;i <= 10;i++)  add(mp[s[x]],x%i,i,x,-1);
            for(int i = 1;i <= 10;i++)  add(mp[ss[0]],x%i,i,x,1);
            s[x] = ss[0];
        }
        else
        {
            int l,r;
            string ss;
            cin >> l >> r >> ss;
            int sum = 0;
            for(int i = 0;i < ss.length()&&l+i <= r;i++)    sum += getsum(mp[ss[i]],(l+i)%ss.length(),ss.length(),r)-getsum(mp[ss[i]],(l+i)%ss.length(),ss.length(),l-1);
            cout << sum << endl;
        }
    }
	return 0;
}
