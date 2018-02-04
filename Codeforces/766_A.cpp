#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string a,b;
    cin >> a >> b;
    if(a == b)  cout << -1 << endl;
    else cout << max(a.length(),b.length()) << endl;
    return 0;
}
