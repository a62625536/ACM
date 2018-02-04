#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int s,x1,x2,t1,t2,p,d;

int main()
{
    cin >> s >> x1 >> x2 >> t1 >> t2 >> p >> d;
    int t = 0,flag1 = 0,flag2 = 0;
    while(flag1 == 0 || flag2 == 0)
    {
        if(flag1)
        {
            if(p == x2) break;
        }
        else if(p == x1)    flag1 = 1;
        if(p == 0 || p == s)    d = -d;
        p += d;
        t++;
    }
    cout << min(t*t1,abs(x1-x2)*t2) << endl;
    return 0;
}
