#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    int a = -2e9,b = 2e9,x,y;
    while(n--)
    {
        cin >> x >> y;
        if(y == 1 && a < 1900)  a = 1900;
        else if(y == 2 && b > 1899) b = 1899;
        a += x;
        b += x;
    }
    if(a > b)   cout << "Impossible" << endl;
    else if(b > 1e9)    cout << "Infinity" << endl;
    else    cout << b << endl;
    return 0;
}
