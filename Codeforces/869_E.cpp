#include<bits/stdc++.h>
#define MOD 998244353
using namespace std;

int n,m,q;
long long tree1[2505][2505] = {0},tree2[2505][2505] = {0};
map<pair<int,int>,long long> mp1,mp2;

inline int lowbit(int x)
{
    return x&(-x);
}

void update(int x,int y,long long w1,long long w2)
{
    for(int i = x;i <= n;i += lowbit(i))
    {
        for(int j = y;j <= m;j += lowbit(j))
        {
            tree1[i][j] += w1;
            tree2[i][j] += w2;
        }
    }
}

void getsum(int x,int y,long long &ans1,long long &ans2)
{
    ans1 = 0;
    ans2 = 0;
    for(int i = x;i > 0;i -= lowbit(i))
    {
        for(int j = y;j > 0;j -= lowbit(j))
        {
            ans1 += tree1[i][j];
            ans2 += tree2[i][j];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> q;
    srand(time(0));
    while(q--)
    {
        int x1,x2,y1,y2,x;
        cin >> x >> x1 >> y1 >> x2 >> y2;
        if(x == 1)
        {
            long long w1 = rand(),w2 = rand();
            update(x1,y1,w1,w2);
            update(x2+1,y1,-w1,-w2);
            update(x1,y2+1,-w1,-w2);
            update(x2+1,y2+1,w1,w2);
            pair<int,int> t = make_pair(x1*10000+y1,x2*10000+y2);
            mp1[t] = w1;
            mp2[t] = w2;
        }
        else if(x == 2)
        {
            pair<int,int> t = make_pair(x1*10000+y1,x2*10000+y2);
            long long w1 = -mp1[t],w2 = -mp2[t];
            update(x1,y1,w1,w2);
            update(x2+1,y1,-w1,-w2);
            update(x1,y2+1,-w1,-w2);
            update(x2+1,y2+1,w1,w2);
        }
        else
        {
            long long sum1,sum2,sum3,sum4;
            getsum(x1,y1,sum1,sum2);
            getsum(x2,y2,sum3,sum4);
            if(sum1 == sum3 && sum2 == sum4)    cout << "Yes" << endl;
            else    cout << "No" << endl;
        }
    }
    return 0;
}
