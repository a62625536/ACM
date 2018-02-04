#include<bits/stdc++.h>
using namespace std;

int n;
string a,b;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int ans1 = 0,ans2 = 0;
    for(int i = 0,j = 0;j < n;j++)
    {
        if(b[j] >= a[i])    i++;
        else    ans1++;
    }
    for(int i = n-1,j = n-1;i >= 0;i--)
    {
        if(b[j] > a[i])
        {
            j--;
            ans2++;
        }
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
