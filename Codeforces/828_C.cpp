#include<bits/stdc++.h>
using namespace std;

char a[2000005] = "";
int n;

int main()
{
	ios::sync_with_stdio(0);
	cin >> n;
	int len = 0;
	while(n--)
	{
		string s;
		int x,now = 0;
		cin >> s >> x;
		while(x--)
		{
			int xx;
			cin >> xx;
			int i = max(now,xx);
			for(int j = i-xx;j < s.length();i++,j++)
			{
				len = max(len,i);
				a[i] = s[j];
			}
			now = max(now,i);
		}
	}
	for(int i = 1;i <= len;i++)
	{
		if(a[i])	cout << a[i];
		else	cout << 'a';
	}
	cout << endl;
	return 0;
}
