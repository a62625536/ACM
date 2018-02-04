#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;
string x,y;

int main()
{
    cin >> x >> y >> n;
    cout << x << " " << y << endl;
    while(n--)
    {
        string a,b;
        cin >> a >> b;
        if(a == x)  x = b;
        else    y = b;
        cout << x << " " << y << endl;
    }
    return 0;
}
