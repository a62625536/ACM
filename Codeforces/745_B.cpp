#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

int n,m,vis[505][505] = {0};
string s[505];

int main()
{
    cin >> n >> m;
    for(int i = 0;i < n;i++)    cin >> s[i];
    int x,y,len1,len2,flag = 0;
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(s[i][j] == 'X')
            {
                flag = 1;
                x = i;
                y = j;
                for(len1 = 1;i+len1 < n && s[i+len1][j] == 'X';len1++);
                for(len2 = 1;j+len2 < m && s[i][j+len2] == 'X';len2++);
                break;
            }
        }
        if(flag)    break;
    }
    for(int i = 0;i < len1;i++)
    {
        for(int j = 0;j < len2;j++)
        {
            if(s[x+i][y+j] == 'X')  vis[x+i][y+j] = 1;
            else
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < m;j++)
        {
            if(s[i][j] == 'X' && !vis[i][j])
            {
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
