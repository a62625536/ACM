#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
char s[260],cnt[4] = {0};

int main()
{
    cin >> n >> s+1;
    if(n%4)
    {
        cout << "===" << endl;
        return 0;
    }
    for(int i = 1;i <= n;i++)
    {
        if(s[i] == 'A') cnt[0]++;
        if(s[i] == 'G') cnt[1]++;
        if(s[i] == 'C') cnt[2]++;
        if(s[i] == 'T') cnt[3]++;
    }
    int t = n/4;
    for(int i = 0;i < 4;i++)
    {
        if(cnt[i] > t)
        {
            cout << "===" << endl;
            return 0;
        }
    }
    for(int i = 1;i<= n;i++)
    {
        if(s[i] == '?')
        {
            if(cnt[0] < t)
            {
                s[i] = 'A';
                cnt[0]++;
            }
            else if(cnt[1] < t)
            {
                s[i] = 'G';
                cnt[1]++;
            }
            else if(cnt[2] < t)
            {
                s[i] = 'C';
                cnt[2]++;
            }
            else
            {
                s[i] = 'T';
                cnt[3]++;
            }
        }
    }
    cout << s+1 << endl;
    return 0;
}
