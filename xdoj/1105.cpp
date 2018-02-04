#include<bits/stdc++.h> 
using namespace std;

int n;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
    	cin >> n;
    	int ans = 0;
    	for(int i = 1;i <= sqrt(n+0.1);i++)
    	{
    		if(n%i == 0)
    		{
    			if(i == n/i)	ans++;
    			else	ans += 2;
			}
		}
		cout << ans << endl;
    }
    return 0;
}
