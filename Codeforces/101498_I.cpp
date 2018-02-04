#include<bits/stdc++.h>
using namespace std;

int n,m;

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        if(n % 2 == 0 && m%2 == 0)  cout << "abdullah" << endl;
        else    cout << "hasan" << endl;
    }
    return 0;
}
