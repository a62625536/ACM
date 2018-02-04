#include<bits/stdc++.h>
using namespace std;

string s;
int ok[128] = {0};
stack<char> ss;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    for(int i = 0;i < s.length();i++)   ok[s[i]] = 1;
    int now = 0;
    for(char i = 'a';i <= 'z';i++)
    {
        if(!ok[i])  continue;
        while(!ss.empty() && ss.top() <= i)
        {
            cout << ss.top();
            ss.pop();
        }
        int t = s.length()-1;
        while(s[t] != i)    t--;
        while(now <= t)
        {
            if(s[now] == i) cout << i;
            else ss.push(s[now]);
            now++;
        }
    }
    while(!ss.empty())
    {
        cout << ss.top();
        ss.pop();
    }
    cout << endl;
    return 0;
}
