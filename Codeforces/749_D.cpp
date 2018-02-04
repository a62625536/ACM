#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;

int n,m,vis[200005] = {0},a[200005],b[200005];
vector<int> v[200005],vv;
vector<int>::iterator it;

int main()
{
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        v[a[i]].push_back(b[i]);
    }
    for(int i = n;i >= 1;i--)
    {
        if(vis[a[i]])   continue;
        vis[a[i]] = 1;
        vv.push_back(a[i]);
    }
    scanf("%d",&m);
    while(m--)
    {
        set<int> s;
        int k;
        scanf("%d",&k);
        for(int i = 1;i <= k;i++)
        {
            int x;
            scanf("%d",&x);
            s.insert(x);
        }
        int max1 = -1,max2 = -1;
        for(int i = 0;i < vv.size();i++)
        {
            if(s.find(vv[i]) == s.end())
            {
                if(max1 == -1)  max1 = vv[i];
                else
                {
                    max2 = vv[i];
                    break;
                }
            }
        }
        if(max1 == -1)  printf("0 0\n");
        else if(max2 == -1) printf("%d %d\n",max1,v[max1].front());
        else
        {
            it = lower_bound(v[max1].begin(),v[max1].end(),v[max2].back());
            printf("%d %d\n",max1,*it);
        }
    }
    return 0;
}
