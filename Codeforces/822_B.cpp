#include<bits/stdc++.h>
using namespace std;

int n,m;
string s1,s2;
vector<int> v;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> m >> s1 >> s2;
    s1 = ' '+s1;
    s2 = ' '+s2;
    int ans = 1e9;
    for(int i = 0;i <= m-n;i++)
    {
        int cnt = 0;
        for(int j = 1;j <= n;j++)
        {
            if(s1[j] != s2[i+j])    cnt++;
        }
        if(cnt < ans)
        {
            ans = cnt;
            v.clear();
            for(int j = 1;j <= n;j++)
            {
                if(s1[j] != s2[i+j])    v.push_back(j);
            }
        }
    }
    cout << ans << endl;
    for(int i = 0;i < v.size();i++) cout << v[i] << " ";
    cout << endl;
    return 0;
}
