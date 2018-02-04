#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
#include<stack>
#include<vector>
using namespace std;

struct xx
{
    xx(string a,int b):s(a),cnt(b){};
    string s;
    int cnt;
};
string s;
stack<xx> st;
vector<string> v[1000005];

int main()
{
    cin >> s;
    int len = s.length(),maxx = 1,now = 0;
    string a = "";
    for(int i = 0;i < len;i++)
    {
        if(s[i] == ',')
        {
            i++;
            int t = 0;
            for(;i < len;i++)
            {
                if(s[i] == ',') break;
                else    t = t*10+s[i]-'0';
            }
            if(!st.empty()) st.top().cnt--;
            st.push(xx(a,t));
            now++;
            maxx = max(maxx,now);
            v[now].push_back(a);
            a = "";
            while(!st.empty())
            {
                if(st.top().cnt == 0)
                {
                    now--;
                    st.pop();
                }
                else    break;
            }
        }
        else    a.append(1,s[i]);
    }
    cout << maxx << endl;
    for(int i = 1;i <= maxx;i++)
    {
        for(int j = 0;j < v[i].size();j++)  cout << v[i][j] << " ";
        cout << endl;
    }
    return 0;
}
