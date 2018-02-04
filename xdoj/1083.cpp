#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int T;
	string s;
	cin >> T;
	while(T--)
	{
		cin >> s;
		int len = s.length(),cnt = 0,ans = 0;
		for(int i = 0;i < len;i++)
		{
			if(s[i] == '(')	cnt++;
			else if(cnt)
			{
				cnt--;
				ans += 2;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
