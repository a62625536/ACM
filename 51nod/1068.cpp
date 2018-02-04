#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> s;
        int sum = 0;
        for(int i = 0;i < s.length();i++)   sum += s[i]-'0';
        if(sum%3)   cout << "A" << endl;
        else    cout << "B" << endl;
    }
    return 0;
}
