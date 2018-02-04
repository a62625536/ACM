#include<bits/stdc++.h>
using namespace std;

int n,k;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n >> k;
	int t = n-k-1;
	if(t%k == 0)    cout << 2+t/k*2 << endl;
	else if(t%k == 1)   cout << 2+t/k*2+1 << endl;
    else    cout << 2+t/k*2+2 << endl;
    int i;
    for(i = n-1;i >= max(n-k,1);i--)    cout << n << " " << i << endl;
    for(;i >= 1;i--)   cout << i+k << " " << i << endl;
	return 0;
}
