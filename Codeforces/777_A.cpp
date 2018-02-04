#include<bits/stdc++.h>
using namespace std;

int n,x;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> x;
    n %= 6;
    if(n%2 && x != 2)   x = 1-x;
    cout << (x+n/2)%3 << endl;
    return 0;
}
