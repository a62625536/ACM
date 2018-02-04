#include <bits/stdc++.h>
using namespace std;

long long a[10000005];
int n;

int main()
{
    ios::sync_with_stdio(false);
    a[0] = 1;
    a[1] = 2;
    for(int i = 2;i <= 10000000;i++)    a[i] = a[i-1]+2*(i-1);
	while(cin >> n) cout << a[n] << endl;
	return 0;
}
