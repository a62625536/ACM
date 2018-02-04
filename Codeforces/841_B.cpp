#include<bits/stdc++.h>
using namespace std;

int n,a[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int cnt = 0;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(a[i]%2)  cnt++;
    }
    if(cnt > 0)   cout << "First" << endl;
    else    cout << "Second" << endl;
    return 0;
}
