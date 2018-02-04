#include<bits/stdc++.h>
using namespace std;

map<char,int> mp1,mp2;
string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> s;
    for(int i = 0;i < s.length();i++)   mp1[s[i]] = 1;
    int now = 0;
    cout << "int[] arr = new int[]{";
    int flag = 0;
    for(char i = '9';i >= '0';i--)
    {
        if(mp1.count(i))
        {
            mp2[i] = now++;
            if(flag)    cout << "," << i;
            else
            {
                cout << i;
                flag = 1;
            }
        }
    }
    cout << "};" << endl;
    cout << "int[] index = new int[]{";
    flag = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(flag)    cout << "," << mp2[s[i]];
        else
        {
            cout << mp2[s[i]];
            flag = 1;
        }
    }
    cout << "};" << endl;
    return 0;
}
