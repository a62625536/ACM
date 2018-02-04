#include<bits/stdc++.h>
using namespace std;

string s;
map<char,int> l,r;
int n,k,sum[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> s;
    s = ' '+s;
    for(int i = 1;i <= n;i++)   r[s[i]] = i;
    for(int i = n;i >= 1;i--)   l[s[i]] = i;
    for(char c = 'A';c <= 'Z';c++)
    {
        sum[l[c]]++;
        sum[r[c]+1]--;
    }
    int maxx = 0;
    for(int i = 1;i <= n;i++)
    {
        sum[i] += sum[i-1];
        maxx = max(maxx,sum[i]);
    }
    if(maxx > k)    cout << "YES" << endl;
    else    cout << "NO" << endl;
	return 0;
}
