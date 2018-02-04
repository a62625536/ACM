#include<bits/stdc++.h>
using namespace std;

int sum[1000005];
int main()
{
    ios::sync_with_stdio(false);
	for(int i = 1;i <= 1000000;i++)
	{
		for(int j = i;j <= 1000000;j += i)	sum[j]++;
	}
	for(int i = 2;i <= 1000000;i++)	sum[i] = (sum[i]+sum[i-1])%1007;
	for(int i = 2;i <= 1000000;i++)	sum[i] = (sum[i]+sum[i-1])%1007;
	int a,b;
	while(cin >> a >> b)	cout << (sum[b]-sum[a-1]+1007)%1007 << endl;
	return 0;
}
