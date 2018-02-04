#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

long long t1,t2,t,a[100005],b[100005] = {0};
int n;

int main()
{
    cin >> t1 >> t2 >> t >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    b[0] = t1;
    for(int i = 1;i <= n;i++)
    {
        if(b[i-1] > a[i])   b[i] = b[i-1]+t;
        else    b[i] = a[i]+t;
    }
    a[n+1] = b[n]+1;
    long long ans,minn = 1e13;
    for(int i = 1;i <= n+1;i++)
    {
        if(b[i-1]+t > t2)   break;
        long long tmp = b[i-1]-a[i]+1;
        if(tmp <= 0)
        {
            ans = b[i-1];
            break;
        }
        else if(tmp < minn)
        {
            ans = a[i]-1;
            minn = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}
