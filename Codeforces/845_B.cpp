#include<bits/stdc++.h>
using namespace std;

int n,sub[6],add[6];
string s;

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    int sum1 = 0,sum2 = 0;
    for(int i = 0;i < 3;i++)
    {
        sum1 += s[i]-'0';
        sub[i] = s[i]-'0';
        add[i] = '9'-s[i];
    }
    for(int i = 3;i < 6;i++)
    {
        sum2 += s[i]-'0';
        sub[i] = s[i]-'0';
        add[i] = '9'-s[i];
    }
    if(sum1 > sum2)
    {
        int t = sum1-sum2;
        int a[6];
        for(int i = 0;i < 3;i++)    a[i] = sub[i];
        for(int i = 3;i < 6;i++)    a[i] = add[i];
        sort(a,a+6);
        reverse(a,a+6);
        for(int i = 0;i < 6;i++)
        {
            t -= a[i];
            if(t <= 0)
            {
                cout << i+1 << endl;
                return 0;
            }
        }
    }
    else if(sum2 > sum1)
    {
        int t = sum2-sum1;
        int a[6];
        for(int i = 0;i < 3;i++)    a[i] = add[i];
        for(int i = 3;i < 6;i++)    a[i] = sub[i];
        sort(a,a+6);
        reverse(a,a+6);
        for(int i = 0;i < 6;i++)
        {
            t -= a[i];
            if(t <= 0)
            {
                cout << i+1 << endl;
                return 0;
            }
        }
    }
    else    cout << 0 << endl;
    return 0;
}
