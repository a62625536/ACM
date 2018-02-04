#include<bits/stdc++.h>
using namespace std;

int n,x[500];
string ans = "z";

int main()
{
    ios::sync_with_stdio(0);
    x[1] = 0;
    for(int i = 2;i <= 440;i++) x[i] = x[i-1]+i-1;
    cin >> n;
    for(char c = 'a';c <= 'z';c++)
    {
        if(n == 0)  break;
        int t = 440;
        while(x[t] > n) t--;
        n -= x[t];
        while(t--)  ans.append(1,c);
    }
    cout << ans << endl;
    return 0;
}
