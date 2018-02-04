#include<bits/stdc++.h>
using namespace std;

int n,k,a[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i = 1;i <= k;i++)   cin >> a[i];
    int cnt4 = n;
    for(int i = 1;i <= k;i++)
    {
        while(a[i] >= 4 && cnt4)
        {
            a[i] -= 4;
            cnt4--;
        }
    }
    int cnt2 = cnt4+2*n;
    for(int i = 1;i <= k;i++)
    {
        while(a[i] >= 2 && cnt2)
        {
            a[i] -= 2;
            cnt2--;
        }
    }
    int cnt1 = cnt2+cnt4;
    for(int i = 1;i <= k;i++)   cnt1 -= a[i];
    if(cnt1 >= 0)   cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
