#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n;
long long k;
struct xx
{
    long long m[20][20];
};

xx mul(xx a,xx b,int len)
{
    xx tmp;
    for(int i = 0;i <= len;i++)
    {
        for(int j = 0;j <= len;j++)
        {
            tmp.m[i][j] = 0;
            for(int k = 0;k <= len;k++)  tmp.m[i][j] = (tmp.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
        }
    }
    return tmp;
}

xx qpower(xx a,long long k,int len)
{
    xx b;
    memset(b.m,0,sizeof(b.m));
    for(int i = 0;i <= len;i++)  b.m[i][i] = 1;
    while(k)
    {
        if(k%2) b = mul(a,b,len);
        a = mul(a,a,len);
        k /= 2;
    }
    return b;
}
int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k;
    xx base,now;
    for(int i = 0;i < 16;i++)
    {
        for(int j = max(0,i-1);j < min(i+2,16);j++)  base.m[i][j] = 1;
    }
    now.m[0][0] = 1;
    for(int i = 1;i <= n;i++)
    {
        long long a,b,c;
        cin >> a >> b >> c;
        for(int j = c+1;j < 16;j++) now.m[j][0] = 0;
        now = mul(qpower(base,min(b,k)-a,c),now,c);
        for(int j = c+1;j < 16;j++) now.m[j][0] = 0;
        if(b >= k)  break;
    }
    cout << now.m[0][0] << endl;
    return 0;
}
