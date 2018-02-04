#include<bits/stdc++.h>
using namespace std;

int a,b;

int main()
{
    ios::sync_with_stdio(0);
    cin >> a >> b;
    int now = 1;
    while(1)
    {
        if(a < now)
        {
            cout << "Vladik" << endl;
            return 0;
        }
        a -= now++;
        if(b < now)
        {
            cout << "Valera" << endl;
            return 0;
        }
        b -= now++;
    }
    return 0;
}
