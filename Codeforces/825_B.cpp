#include<bits/stdc++.h>
using namespace std;

string s[15];

bool ok()
{
    for(int i = 1;i <= 10;i++)
    {
        for(int j = 1;j <= 10;j++)
        {
            if(i <= 6)
            {
                int flag = 1;
                for(int ii = i;ii < i+5;ii++)
                {
                    if(s[ii][j] != 'X') flag = 0;
                }
                if(flag)    return 1;
            }
            if(j <= 6)
            {
                int flag = 1;
                for(int jj = j;jj < j+5;jj++)
                {
                    if(s[i][jj] != 'X') flag = 0;
                }
                if(flag)    return 1;
            }
            if(i <= 6 && j <= 6)
            {
                int flag = 1;
                for(int ii = i,jj = j;ii < i+5;ii++,jj++)
                {
                    if(s[ii][jj] != 'X')    flag = 0;
                }
                if(flag)    return 1;
            }
            if(i >= 5 && j <= 6)
            {
                int flag = 1;
                for(int ii = i,jj = j;ii > i-5;ii--,jj++)
                {
                    if(s[ii][jj] != 'X')   flag = 0;
                }
                if(flag)    return 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(0);
    for(int i = 1;i <= 10;i++)
    {
        cin >> s[i];
        s[i] = ' '+s[i];
    }
    for(int i = 1;i <= 10;i++)
    {
        for(int j = 1;j <= 10;j++)
        {
            if(s[i][j] != '.') continue;
            s[i][j] = 'X';
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
