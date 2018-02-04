#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

string s,a,b;

int main()
{
    cin >> s;
    for(char i = 'a';i <= 'z';i++)
    {
        for(int j = 0;j <= s.length();j++)
        {
            a = s;
            a.insert(a.begin()+j,i);
            b = a;
            reverse(a.begin(),a.end());
            if(a == b)
            {
                cout << a << endl;
                return 0;
            }
        }
    }
    cout << "NA " << endl;
    return 0;
}
