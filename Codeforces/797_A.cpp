#include<bits/stdc++.h>
using namespace std;

int n,k;
vector <int> ans;
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int cnt = 0;
    if(k == 1)
    {
        cout << n <<endl;
        return 0;
    }
    for(int i = 2;i <= n;i++)
    {
        while(n%i == 0)
        {
            ans.push_back(i);
            n /= i;
            cnt++;
            if(cnt == k-1 && n > 1 || cnt == k && n == 1)
            {
                for(int j = 0;j < ans.size();j++)   cout << ans[j] << " ";
                if(n > 1)   cout  << n;
                return 0;
            }
        }
    }
    cout << -1 << endl;
    return 0;
}
