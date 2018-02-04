#include<bits/stdc++.h>
using namespace std;

int n;
map<string,int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        string s1,s2,s = "";
        cin >> s1 >> s2;
        for(int i = s2.length()-1;i >= 0;i--)
        {
            if((s2[i]-'0')%2)   s = "1"+s;
            else    s = "0"+s;
        }
        while(s.length() < 18)  s = "0"+s;
        if(s1 == "+")   mp[s]++;
        else if(s1 == "-")  mp[s]--;
        else    cout << mp[s] << endl;
    }
    return 0;
}

