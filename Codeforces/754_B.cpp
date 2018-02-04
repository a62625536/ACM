#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

string s[4];

bool ok()
{
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            if(s[i][j] == 'x' && s[i][j+1] == 'x' && s[i][j+2] == 'x')  return 1;
        }
    }
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(s[i][j] == 'x' && s[i+1][j] == 'x' && s[i+2][j] == 'x')  return 1;
        }
    }
    for(int i = 0;i < 2;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            if(s[i][j] == 'x' && s[i+1][j+1] == 'x' && s[i+2][j+2] == 'x')  return 1;
        }
    }
    for(int i = 2;i < 4;i++)
    {
        for(int j = 0;j < 2;j++)
        {
            if(s[i][j] == 'x' && s[i-1][j+1] == 'x' && s[i-2][j+2] == 'x')  return 1;
        }
    }
    return 0;
}

int main()
{
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i = 0;i < 4;i++)
    {
        for(int j = 0;j < 4;j++)
        {
            if(s[i][j] != '.')  continue;
            s[i][j] = 'x';
            if(ok())
            {
                cout << "YES" << endl;
                return 0;
            }
            s[i][j] = '.';
        }
    }
    cout << "NO" << endl;
    return 0;
}
