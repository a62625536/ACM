#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

string op,s;
int x,n;

int main()
{
    cin >> n;
    int l = -INF,r = INF;
    while(n--)
    {
        cin >> op >> x >> s;
        if(op == ">" && s == "Y" || op == "<=" && s == "N") l = max(l,x+1);
        else if(op == ">=" && s == "Y" || op == "<" && s == "N")    l = max(l,x);
        else if(op == "<" && s == "Y" || op == ">=" && s == "N")    r = min(r,x-1);
        else if(op == "<=" && s == "Y" || op == ">" && s == "N")    r = min(r,x);
    }
    if(l <= r)  cout << l << endl;
    else    cout << "Impossible" << endl;
    return 0;
}
