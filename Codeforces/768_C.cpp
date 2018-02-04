#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int n,k,x;
vector<int> v[100005];

int main()
{
    cin >> n >> k >> x;
    for(int i = 1;i <= n;i++)
    {
        int t;
        cin >> t;
        v[0].push_back(t);
    }
    sort(v[0].begin(),v[0].end());
    for(int i = 1;i <= k;i++)
    {
        v[i] = v[i-1];
        for(int j = 0;j < n;j += 2) v[i][j] ^= x;
        sort(v[i].begin(),v[i].end());
        for(int j = 0;j < i;j++)
        {
            if(v[j] == v[i])
            {
                int t = i-j;
                int tt = (k-j)%t+j;
                cout << v[tt][n-1] << " " << v[tt][0] << endl;
                return 0;
            }
        }
    }
    cout <<  v[k][n-1] << " " << v[k][0] << endl;
    return 0;
}
