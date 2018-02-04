#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include <iomanip>
using namespace std;

int n,n1,n2,a[100005];

int main()
{
    cin >> n >> n1 >> n2;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    if(n1 > n2) swap(n1,n2);
    int t1 = n1,t2 = n2;
    sort(a+1,a+1+n);
    int i = n;
    double ans = 0,sum = 0;
    while(t1--) sum += a[i--];
    ans += sum/n1;
    sum = 0;
    while(t2--) sum += a[i--];
    ans += sum/n2;
    cout << setprecision(8) << ans << endl;
    return 0;
}
