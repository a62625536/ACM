//#include<iostream>
//#include<cstdio>
//#include<cstring>
//#include<algorithm>
//using namespace std;
//  
//int n,m,l;
//int linker[505];  
//bool used[505];  
//int g[505][505];
//
//bool dfs(int u)
//{
//    for(int v = 0;v < m;v++)
//    {
//    	if(g[u][v] && !used[v])
//		{
//	        used[v] = 1;
//	        if(linker[v] == -1 || dfs(linker[v]))
//			{
//	            linker[v] = u;
//	            return 1;
//	        }  
//	    }  
//	}
//    return 0;  
//}  
//
//int MaxMatch()
//{  
//    int ans = 0;  
//    memset(linker,-1,sizeof(linker));  
//    for(int i = 0;i < n;i++)
//	{  
//        memset(used,0,sizeof(used));
//        if(dfs(i))	ans++;
//    }
//    return ans;
//}  
//   
//int main()
//{  
//    int a,b;  
//    while(~scanf("%d%d",&n,&m))
//	{   
//		memset(g,0,sizeof(g));
//        scanf("%d",&l);
//        for(int i = 0;i < l;i++)
//		{  
//            scanf("%d%d",&a,&b);  
//            g[a][b] = 1;
//        }  
//        printf("%d\n",MaxMatch());
//    }  
//    return 0;     
//} 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector> 
using namespace std;
  
int n,m,l;
int linker[505];  
bool used[505];  
vector<int> v[505];

bool dfs(int u)
{
    for(int i = 0;i < v[u].size();i++)
    {
    	int t = v[u][i];
    	if(!used[t])
		{
	        used[t] = 1;
	        if(linker[t] == -1 || dfs(linker[t]))
			{
	            linker[t] = u;
	            return 1;
	        }  
	    }  
	}
    return 0;  
}  

int MaxMatch()
{  
    int ans = 0;  
    memset(linker,-1,sizeof(linker));  
    for(int i = 0;i < n;i++)
	{  
        memset(used,0,sizeof(used));
        if(dfs(i))	ans++;
    }
    return ans;
}  
   
int main()
{  
    int a,b;  
    while(~scanf("%d%d",&n,&m))
	{   
		for(int i = 0;i < n;i++)	v[i].clear();
        scanf("%d",&l);
        for(int i = 0;i < l;i++)
		{  
            scanf("%d%d",&a,&b);  
            v[a].push_back(b);
        }  
        printf("%d\n",MaxMatch());
    }  
    return 0;     
} 
