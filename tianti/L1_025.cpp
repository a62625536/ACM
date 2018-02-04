#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    std::ios::sync_with_stdio(false);
    getline(cin,s);
    int i,a = 0,b = 0,flag = 0;
    for(i = 0;i < s.length() && s[i] != ' ';i++)
    {
        if(flag)    continue;
        if('0' <= s[i] && s[i] <= '9')  a = a*10+s[i]-'0';
        else
        {
            a = -1;
            flag = 1;
        }
    }
    for(i++;i < s.length();i++)
    {
        if('0' <= s[i] && s[i] <= '9')  b = b*10+s[i]-'0';
        else
        {
            b = -1;
            break;
        }
    }
    if(1 <= a && a <= 1000 && 1 <= b && b <= 1000)  cout << a << " + " << b << " = " << a+b << endl;
    else if(1 <= a && a <= 1000)    cout << a << " + ? = ?" << endl;
    else if(1 <= b && b <= 1000)    cout << "? + " << b << " = ?" << endl;
    else    cout << "? + ? = ?" << endl;
    return 0;
}
