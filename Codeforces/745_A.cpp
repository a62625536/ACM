#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<set>
using namespace std;

string a;
set<string> s;

int main()
{
    cin >> a;
    for(int i = 0;i < a.length();i++)
    {
        string t = a.substr(a.length()-i-1,a.length())+a.substr(0,a.length()-i);
        s.insert(t);
    }
    cout << s.size() << endl;
    return 0;
}

