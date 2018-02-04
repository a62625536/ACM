#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

string s;

int main()
{
	while(cin >> s)
	{
		int len = s.length();
		int ans = 0,flag = 0;
		for(int now = 0;now < len;now++)
		{
			if(flag)
			{
				while(now < len)
				{
					if(s[now] == '1')
					{
						ans++;
						flag = 0;
						break;
					}
					else	now++;
				}
			}
			else if(s[now] == '0')	flag = 1;
		}
		if(flag)	ans++;
		printf("%d\n",ans);
	}
	return 0;
} 
