#include<bits/stdc++.h>
using namespace std;

int n,k,c;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n >> k >> c;
    int num = k/n;
    if(num*n >= c)  cout << c << endl;
    else   cout << n-k/(num+1)+c << endl;
    return 0;
}
