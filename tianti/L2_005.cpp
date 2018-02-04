#include<bits/stdc++.h>
using namespace std;

int n,m,a[55][10005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i][0];
        for(int j = 1;j <= a[i][0];j++) cin >> a[i][j];
        sort(a[i]+1,a[i]+1+a[i][0]);
        a[i][0] = unique(a[i]+1,a[i]+1+a[i][0])-a[i]-1;
    }
    cin >> m;
    while(m--)
    {
        int x,y;
        cin >> x >> y;
        int now1 = 1,now2 = 1,cnt1 = 0,cnt2 = 0;
        while(now1 <= a[x][0] && now2 <= a[y][0])
        {
            if(a[x][now1] < a[y][now2])
            {
                cnt2++;
                now1++;
            }
            else if(a[x][now1] > a[y][now2])
            {
                cnt2++;
                now2++;
            }
            else
            {
                cnt1++;
                cnt2++;
                now1++;
                now2++;
            }
        }
        while(now1 <= a[x][0])
        {
            cnt2++;
            now1++;
        }
        while(now2 <= a[y][0])
        {
            cnt2++;
            now2++;
        }
        cout << fixed << setprecision(2) << (double)cnt1/cnt2*100 << "%" << endl;
    }
    return 0;
}
