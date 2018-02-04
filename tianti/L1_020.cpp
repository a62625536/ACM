#include<bits/stdc++.h>
using namespace std;

map<string,int> mp1,mp2;
int n,m;
string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        int k;
        cin >> k;
        for(int i = 1;i <= k;i++)
        {
            cin >> s;
            if(k != 1)  mp1[s] = 1;
        }
    }
    cin >> m;
    int flag = 0;
    while(m--)
    {
        cin >> s;
        if(!mp1.count(s) && !mp2.count(s))
        {
            if(flag)    cout << " " << s;
            else    cout << s;
            mp2[s] = 1;
            flag = 1;
        }
    }
    if(!flag)   cout << "No one is handsome" << endl;
    return 0;
}
