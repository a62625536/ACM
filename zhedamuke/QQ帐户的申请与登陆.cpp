#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

map<string,string>mp;
string op,a,b;
int n;

int main()
{
    cin >> n;
    while(n--)
    {
        cin >> op >> a >> b;
        if(op[0] == 'N')
        {
            if(mp.count(a)) cout << "ERROR: Exist" << endl;
            else
            {
                mp[a] = b;
                cout << "New: OK" << endl;
            }
        }
        else
        {
            if(!mp.count(a))    cout << "ERROR: Not Exist" << endl;
            else if(mp[a] == b) cout << "Login: OK" << endl;
            else    cout << "ERROR: Wrong PW" << endl;
        }
    }
    return 0;
}
