#include<bits/stdc++.h>
using namespace std;

string s1,s2;

int main()
{
    ios::sync_with_stdio(false);
	cin >> s1 >> s2;
	string s3;
	int flag = 0;
	for(int
     i = 0;i < s1.length();i++)
    {
        if(s2[i] <= s1[i])  s3 = s3+s2[i];
        else
        {
            flag = 1;
        }
    }
    if(flag)    cout << -1<< endl;
    else    cout << s3 << endl;

	return 0;
}
