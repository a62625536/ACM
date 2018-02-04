#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    std::ios::sync_with_stdio(false);
    int a = 0,b = 0,c = 0,d = 0;
    cin >> s;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == 'G' || s[i] == 'g')  a++;
        if(s[i] == 'P' || s[i] == 'p')  b++;
        if(s[i] == 'L' || s[i] == 'l')  c++;
        if(s[i] == 'T' || s[i] == 't')  d++;
    }
    while(a || b || c || d)
    {
        if(a)
        {
            cout << "G";
            a--;
        }
        if(b)
        {
            cout << "P";
            b--;
        }
        if(c)
        {
            cout << "L";
            c--;
        }
        if(d)
        {
            cout << "T";
            d--;
        }
    }
    cout << endl;
    return 0;
}
