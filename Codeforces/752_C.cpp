#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
string s;
int x = 0,y = 0;

int main()
{
    cin >> n >> s;
    int ans = 1;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'L')
        {
            if(x == 0)  x = -1;
            else if(x == 1)
            {
                ans++;
                x = -1;
                y = 0;
            }
        }
        else if(s[i] == 'R')
        {
            if(x == 0)  x = 1;
            else if(x == -1)
            {
                ans++;
                x = 1;
                y = 0;
            }
        }
        else if(s[i] == 'U')
        {
            if(y == 0)  y = 1;
            else if(y == -1)
            {
                ans++;
                y = 1;
                x = 0;
            }
        }
        else
        {
            if(y == 0)  y = -1;
            else if(y == 1)
            {
                ans++;
                y = -1;
                x = 0;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
