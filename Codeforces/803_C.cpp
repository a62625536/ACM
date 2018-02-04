#include<bits/stdc++.h>
using namespace std;

long long n,k;

int main()
{
    ios::sync_with_stdio(fals#include<bits/stdc++.h>
using namespace std;

long long n,k;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if(log(n*2) < log(k)+log(k+1)-1e-9)
    {
        cout << -1 << endl;
        return 0;
    }
    long long t = k*(k+1)/2,maxx = 1;
    for(long long i = 1;i*i <= n;i++)
    {
        if(n%i) continue;
        {
            if(i*t <= n)    maxx = max(maxx,i);
            if(t <= i)  maxx = max(maxx,n/i);
        }
    }
    for(long long i = 1;i < k;i++)   cout << i*maxx << " ";
    cout << n-maxx*k*(k-1)/2 << endl;
    return 0;
}
e);
    cin >> n >> k;
    if(log(n*2) > log(k)+log(k+1)-1e-9)
    {
        cout << -1 << endl;
        return 0;
    }
    long long t = k*(k+1)/2,maxx = 1;
    for(long long i = 1;i*i <= n;i++)
    {
        if(n%i) continue;
        {
            if(i*t <= n)    maxx = max(maxx,i);
            if(n/i*t <= n)  maxx = max(maxx,n/i);
        }
    }
    for(int i = 1;i <= n;i++)   cout << i*maxx << " ";
    cout << n-maxx*k*(k-1)/2 << endl;
    return 0;
}
