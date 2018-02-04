#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,m,k;

int main()
{
    cin >> n >> m >> k;
    int ans3 = k&1?1:0,t = (k+1)>>1;
    int ans2 = t%m;
    if(ans2 == 0)   ans2 = m;
    t += m-ans2;
    int ans1 = t/m;
    cout << ans1 << " " << ans2 << " ";
    if(ans3)    cout << "L" << endl;
    else    cout << "R" << endl;
    return 0;
}
