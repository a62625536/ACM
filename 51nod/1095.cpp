#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

map<string,int> mp1,mp2;
int n;

int main()
{
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        mp1[s]++;
        sort(s.begin(),s.end());
        mp2[s]++;
    }
    cin >> n;
    while(n--)
    {
        string s;
        cin >> s;
        int t = mp1[s];
        sort(s.begin(),s.end());
        cout << mp2[s]-t << endl;
    }
    return 0;
}
