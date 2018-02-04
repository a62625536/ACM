#include<bits/stdc++.h>
using namespace std;

string s;

int f(char c)
{
    if(0 <= c && c <= '9') return c-'0';
    return c-'A'+10;
}

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    int sum = 0,maxx = 0;
    for(int i = 0;i < s.length();i++)
    {
        sum += f(s[i]);
        maxx = max(maxx,f(s[i]));
    }
    for(int i = maxx+1;i <= 36;i++)
    {
        if(sum%(i-1) == 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}
