#include<bits/stdc++.h>
using namespace std;

int a[1005],n;

int main()
{
    ios::sync_with_stdio(false);
    while(cin >> n)
    {
        int flag = 1;
        for(int i = 1;i <= n;i++)   cin >> a[i];
        sort(a+1,a+1+n);
        for(int i = 1;i <= n-2;i++)
        {
            for(int j = i+1;j <= n-1;j++)
            {
                int sum = -a[i]-a[j];
                int pos = lower_bound(a+j+1,a+n+1,sum)-a;
                if(pos != n+1 && a[pos] == sum)
                {
                    flag = 0;
                    cout << a[i] << " " << a[j] << " " << a[pos] << endl;
                }
            }
        }
        if(flag)    cout << "Ren Chou Jiu Gai Duo Du Shu!" << endl;
    }
    return 0;
}
