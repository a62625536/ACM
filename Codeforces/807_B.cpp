#include<bits/stdc++.h>
using namespace std;

int x,y,p,a[30];

int main()
{
    ios::sync_with_stdio(false);
    cin >> p >> x >> y;
    int xx = x;
    while(x >= y)
    {
        int t = x/50%475;
        for(int i = 1;i <= 25;i++)
        {
            t = (t*96+42)%475;
            a[i] = t+26;
            if(a[i] == p)
            {
                cout << 0 << endl;
                return 0;
            }
        }
        x -= 50;
    }
    x = xx;
    int cnt = 0,now = 1;
    while(1)
    {
        int t = x/50%475;
        for(int i = 1;i <= 25;i++)
        {
            t = (t*96+42)%475;
            a[i] = t+26;
            if(a[i] == p)
            {
                cout << cnt << endl;
                return 0;
            }
        }
        x += 50;
        now++;
        if(now == 2)
        {
            now = 0;
            cnt++;
        }
    }
    return 0;
}
