#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define LL __int64
using namespace std;

int main()
{
    int n;
    map<LL,LL> mp;
    cin >> n;
    while(n--)
    {
        string s;
        LL num = 0,now = 1,temp;
        cin >> s >> temp;
        while(temp)
        {
            num += temp%2*now;
            now *= 10;
            temp /= 10;
        }
        if(s == "+")    mp[num]++;
        else if(s =="-") mp[num]--;
        else
        {
            cout << mp[num] << endl;
        }
    }
    return 0;
}
