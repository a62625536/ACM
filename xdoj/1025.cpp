#include<bits/stdc++.h>
using namespace std;

vector<int> make[10005];
int v[10005],c[10005],sum[10005],n,m,w;

int dfs(int x)
{
    if(sum[x] == -1)
    {
        if(make[x].empty()) sum[x] = v[x];
        else
        {
            int ans = w;
            for(int i = 0;i < make[x].size();i++)  ans += dfs(make[x][i]);
            sum[x] = min(ans,v[x]);
        }
    }
    return sum[x];
}
int main()
{
    ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--)
	{
	    memset(sum,-1,sizeof(sum));
		cin >> n >> m >> w;
		for(int i = 0;i < n;i++)	make[i].clear();
		for(int i = 0;i < n;i++)
		{
			cin >> v[i] >> c[i];
			for(int j = 0;j < c[i];j++)
			{
				int temp;
				cin >> temp;
				make[i].push_back(temp);
			}
		}
		int ans = 0;
		for(int i = 0;i < m;i++)
		{
			int temp;
			cin >> temp;
			ans += dfs(temp);
		}
		cout << ans << endl;
	}
	return 0;
}

