#include<bits/stdc++.h> 
using namespace std;

string s;
stack<char> ss;

int main()
{
	ios::sync_with_stdio(false);
    while(cin >> s)
    {
        if(s.length() == 1)
        {
        	cout << "1 10" << endl;
        	cout << 0 << " " << s[0] << endl;
        	continue;
        }
        for(int i = 0;i < s.length();i++)  ss.push(s[i]);
        cout << s.length()-1 << " " << 10 << endl;
        cout << ss.top();
        ss.pop();
        while(!ss.empty())
        {
            cout << " " << ss.top();;
            ss.pop();
        }
        cout << endl;
    }
    return 0;
}
