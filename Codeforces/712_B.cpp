#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    int a = 0,b = 0;
    cin >> s;
    for(int i = 0;i < s.size();i++)
    {
        if(s[i] == 'L') a++;
        else if(s[i] == 'R')    a--;
        else if(s[i] == 'U')    b++;
        else if(s[i] == 'D')    b--;
    }
    a = a>0?a:-a;
    b = b>0?b:-b;
    if((a+b)%2) cout << -1 << endl;
    else    cout << (a+b)/2 <<  endl;
    return 0;
}
