#include<bits/stdc++.h>
using namespace std;

long long n;

int findd(long long n,int x,int y)
{
    if(n%x == 0)    return findd(n/x,x+1,y+1);
    return y;
}

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int endd = sqrt(n),ans = 0,l,r;
    for(int i = 2;i <= endd;i++)
    {
        if(n%i == 0)
        {
            int now = findd(n/i,i+1,1);
            if(now > ans)
            {
                ans = now;
                l = i;
            }
        }
    }
    if(ans == 0)
    {
        cout << 1 << endl;
        cout << n << endl;
        return 0;
    }
    cout << ans << endl;
    cout << l;
    for(int i = 1;i < ans;i++) cout << "*" << i+l;
    cout << endl;
    return 0;
}
