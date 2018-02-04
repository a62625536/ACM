#include<bits/stdc++.h>
using namespace std;

int n;
string s,c;

int main()
{
    cin >> n >> c;
    getchar();
    getline(cin,s);
    int len = s.length();
    if(len > n)
    {
        for(int i = len-n;i < len;i++)    cout << s[i];
        cout << endl;
    }
    else
    {
        while(len++ < n)    cout << c;
        cout << s << endl;
    }
    return 0;
}
