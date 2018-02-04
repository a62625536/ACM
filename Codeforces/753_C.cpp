#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#define MOD 1000000007
using namespace std;

int n,m;
vector<int> v[1000005];

int main()
{
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        int t;
        cin >> t;
        while(t--)
        {
            int x;
            cin >> x;
            v[x].push_back(i);
        }
    }
    sort(v+1,v+1+m);
    long long ans = 1,k = 1;
    for(int i = 2;i <= m;i++)
    {
        if(v[i] == v[i-1])
        {
            k++;
            ans = ans*k%MOD;
        }
        else    k = 1;
    }
    cout << ans << endl;
    return 0;

}
