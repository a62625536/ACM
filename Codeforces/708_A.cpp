#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int i;
    for(i = 0;i < s.size() && s[i] == 'a';i++);
    if(i == s.size())   s[i-1] = 'z';
    else
    {
        for(;i < s.size() && s[i] != 'a';i++)   s[i] = s[i]-1;
    }
    cout << s << endl;
    return 0;
}
