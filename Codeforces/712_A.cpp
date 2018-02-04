#include<iostream>
#include<cstring>
using namespace std;

long long a[100005];

int main()
{
    long long last,now,n,i;
    cin >> n;
    for(i = 1;i <= n;i++)   cin >> a[i];
    for(i = 1;i < n;i++)    cout << a[i]+a[i+1] << ' ';
    cout << a[i] << endl;
    return 0;
}
