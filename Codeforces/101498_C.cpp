#include<bits/stdc++.h>
using namespace std;

int a,b,c;

int main()
{
    ios::sync_with_stdio(0);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> a >> b >> c;
        if(a < b && a < c)  cout << "First" << endl;
        else if(b < a && b < c) cout << "Second" << endl;
        else    cout << "Third" << endl;
    }
    return 0;
}
