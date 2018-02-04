#include<bits/stdc++.h>
#define LL long long
using namespace std;

string s;

int main()
{
	ios::sync_with_stdio(false);
    while(cin >> s)
    {
        LL t = 0,x = 0,y = 0;
        int i = 0,len = s.length();
        int a = 0,b = 0;
        for(;i < len && s[i] != '.';i++)    t = t*10+s[i]-'0';
        i++;
        for(;i < len && s[i] != '_';i++)
        {
            x = x*10+s[i]-'0';
            a++;
        }
        i++;
        y = x;
        for(;i < len && s[i] != '.';i++)
        {
            y = y*10+s[i]-'0';
            b++;
        }
        LL sub,mom,z = 0;
        if(a == 0 && b != 0)
        {
            while(b--)  z = z*10+9;
            LL g = __gcd(y,z);
            sub = y/g,mom = z/g;
        }
        else if(a == 0 && b == 0)
        {
            sub = 0;
            mom = 1;
        }
        else if(b == 0)
        {
            z = 1;
            while(a--)  z *= 10;
            LL g = __gcd(x,z);
            sub = x/g,mom = z/g;
        }
        else
        {
            y -= x;
            while(b--)  z = z*10+9;
            while(a--)  z *= 10;
            LL g = __gcd(y,z);
            sub = y/g,mom = z/g;
        }
        sub += t*mom;
        cout << sub << "/" << mom << endl;
    }
    return 0;
}
