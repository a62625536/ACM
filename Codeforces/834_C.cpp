#include<bits/stdc++.h>
using namespace std;

map<long long,int> mp;
int n;
long long a,b;

int main()
{
    ios::sync_with_stdio(0);
    for(long long i = 1;i <= 1000000;i++) mp[i*i*i] = i;
    scanf("%d",&n);
    while(n--)
    {
         scanf("%d%d",&a,&b);
         long long t = a*b;
         if(mp.count(t))
         {
             long long tt = mp[t];
             if(a%tt == 0 && b%tt == 0) printf("Yes\n");
             else   printf("No\n");
         }
         else   printf("No\n");
    }
	return 0;
}
