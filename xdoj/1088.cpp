#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

string s[100005];
int n;

bool cmp(string x,string y)
{
	string X = x+y,Y = y+x;
	return X > Y;
}

int main()
{
	while(cin >> n)
	{
		for(int i = 1;i <= n;i++)	cin >> s[i];
		sort(s+1,s+1+n,cmp);
		for(int i = 1;i <= n;i++)	cout << s[i];
		cout << endl;
	}
	return 0;
}
