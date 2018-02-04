#include<bits/stdc++.h>
using namespace std;

string s;
int num1[100005],num2[100005];

int main()
{
    ios::sync_with_stdio(false);
    cin >> s;
    int sum = 0,cnt1 = 0,cnt2 = 0,ok = 0;
    for(int i = 0;i < s.length();i++)
    {
        int t = s[i]-'0';
        sum += t;
        if(t == 0)  ok = 1;
        if(t%3 == 1)    num1[++cnt1] = i;
        else if(t%3 == 2)   num2[++cnt2] = i;
    }
    if(sum%3 == 0)  cout << s << endl;
    else if(sum %3 == 1)
    {
        string a = "",b = "";
        if(cnt1 >= 1)
        {
            a = s;
            a.erase(a.begin()+num1[cnt1]);
            while(a.length() > 0 && a[0] == '0')  a.erase(a.begin());
            if(a.length() == 0 && ok == 1)  a = "0";
        }
        if(cnt2 >= 2)
        {
            b = s;
            b.erase(b.begin()+num2[cnt2]);
            b.erase(b.begin()+num2[cnt2-1]);
            while(b.length() > 0 && b[0] == '0')    b.erase(b.begin());
            if(b.length() == 0 && ok == 1)  b = "0";
        }
        string ans;
        if(a.length() > b.length()) ans = a;
        else    ans = b;
        if(ans.length())    cout << ans << endl;
        else    cout << -1 << endl;
    }
    else
    {
        string a = "",b = "";
        if(cnt1 >= 2)
        {
            a = s;
            a.erase(a.begin()+num1[cnt1]);
            a.erase(a.begin()+num1[cnt1-1]);
            while(a.length() > 0 && a[0] == '0')  a.erase(a.begin());
            if(a.length() == 0 && ok == 1)  a = "0";
        }
        if(cnt2 >= 1)
        {
            b = s;
            b.erase(b.begin()+num2[cnt2]);
            while(b.length() > 0 && b[0] == '0')    b.erase(b.begin());
            if(b.length() == 0 && ok == 1)  b = "0";
        }
        string ans;
        if(a.length() > b.length()) ans = a;
        else    ans = b;
        if(ans.length())    cout << ans << endl;
        else    cout << -1 << endl;
    }
    return 0;
}
