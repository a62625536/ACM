#include<bits/stdc++.h>
using namespace std;

long long x,y,z;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> x >> y >> z;
    if(x <= y && y <= z)    cout << x << "->" << y << "->" << z << endl;
    else if(x <= z && z <= y)   cout << x << "->" << z << "->" << y << endl;
    else if(y <= x && x <= z)   cout << y << "->" << x << "->" << z << endl;
    else if(y <= z && z <= x)   cout << y << "->" << z << "->" << x << endl;
    else if(z <= x && x <= y)   cout << z << "->" << x << "->" << y << endl;
    else    cout << z << "->" << y << "->" << x << endl;
    return 0;
}
