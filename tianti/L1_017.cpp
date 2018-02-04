#include<bits/stdc++.h>
using namespace std;

string s;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> s;
    double now = 1,cnt = 0,cnt2 = 0;
    for(int i = 0;i < s.length();i++)
    {
        if(s[i] == '-') now *= 1.5;
        else
        {
            cnt2++;
            if(s[i] == '2')    cnt++;
        }
    }
    if((s[s.length()-1]-'0')%2 == 0)    now *= 2;
    cout << fixed << setprecision(2) << now*cnt/cnt2*100 << "%" << endl;
    return 0;
}
