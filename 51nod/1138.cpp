#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> n;
    int flag = 0;
    for(int i = sqrt(n*2);i >= 2;i--)
    {
        if((n-(i-1)*i/2)%i == 0)
        {
            cout << (n-(i-1)*i/2)/i << endl;
            flag = 1;
        }
    }
    if(!flag)   cout << "No Solution" << endl;
    return 0;
}
