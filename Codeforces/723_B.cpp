#include<bits/stdc++.h>
using namespace std;

int n;
string s;

int main()
{
    cin >> n;
    getchar();
    getline(cin,s);
    int maxx = 0,cnt = 0,now = 0,flag = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == '(')
        {
            flag = 1;
            now = 0;
        }
        else if(s[i] == ')')
        {
            flag = 0;
            if(now) cnt++;
            now = 0;
        }
        else if(s[i] == '_')
        {
            if(flag == 1 && now)    cnt++;
            now = 0;
        }
        else
        {
            now++;
            if(flag == 0)   maxx = max(maxx,now);
        }
    }
    cout << maxx << " " << cnt << endl;
	return 0;
 }

