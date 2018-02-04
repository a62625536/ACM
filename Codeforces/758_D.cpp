#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;

long long n,ans = 0;
string s;

int main()
{
    cin >> n >> s;
    if(s[0] == '0')
    {
        cout << "0" << endl;
        return 0;
    }
    long long now = 0,t = 1,nn = 1;
    for(int i = s.length()-1;i >= 0;i--)
    {
        if(s[i] != '0')
        {
            long long sum = now+(s[i]-'0')*t;
            if(sum >= n)
            {
                ans += nn*now;
                nn *= n;
                now = 0;
                t = 1;
                i++;
            }
            else
            {
                now = sum;
                t *= 10;
            }
        }
        else
        {
            long long sum = now;
            int j = i-1;
            while(s[j] == '0')  j--;
            int k = i;
            while(k >= j)
            {
                if(t >= n)  break;
                sum += (s[k]-'0')*t;
                t *= 10;
                k--;
            }
            if(sum < n && k == j-1)
            {
                now = sum;
                i = j;
            }
            else
            {
                if(now != 0)    i++;
                ans += nn*now;
                nn *= n;
                now = 0;
                t = 1;
            }
        }
    }
    ans += nn*now;
    cout << ans << endl;
    return 0;
}
