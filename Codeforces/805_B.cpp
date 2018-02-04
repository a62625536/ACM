#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int now = 0,cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        if(now == 0)    cout << "a";
        else    cout << "b";
        cnt++;
        if(cnt == 2)
        {
            cnt = 0;
            now = 1-now;
        }
    }
    cout << endl;

    return 0;
}
