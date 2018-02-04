#include<bits/stdc++.h>
using namespace std;

string s1,s2;
map<char,int> mp;
int n;

int main()
{
    ios::sync_with_stdio(0);
    mp['v'] = 0;
    mp['<'] = 1;
    mp['^'] = 2;
    mp['>'] = 3;
    cin >> s1 >> s2 >> n;
    int x = mp[s1[0]],y = mp[s2[0]];
    n %= 4;
    if((x+n)%4 == y && (x-n+4)%4 == y)  cout << "undefined" << endl;
    else if((x+n)%4 == y)   cout << "cw" << endl;
    else    cout << "ccw" << endl;
	return 0;
}
