#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int x1,x2,y1,y2,x,y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    int xx = abs(x1-x2),yy = abs(y1-y2);
    if(xx%x || yy%y)
    {
        cout << "NO" << endl;
        return 0;
    }
    if(xx/x%2 == yy/y%2)    cout << "YES" << endl;
    else    cout << "NO" << endl;
    return 0;
}
