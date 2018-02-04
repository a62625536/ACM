#include<bits/stdc++.h>
using namespace std;

int s,v1,v2,t1,t2;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int x1 = s*v1+2*t1,x2 = s*v2+2*t2;
    if(x1 < x2) cout << "First" << endl;
    else if(x1 > x2)    cout << "Second" << endl;
    else    cout << "Friendship" << endl;
    return 0;
}
