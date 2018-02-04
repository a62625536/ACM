#include<bits/stdc++.h>
#define MOD 1000000009
using namespace std;

int n,h;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> h;
    for(int i = 1;i < n;i++)
    {
        cout << fixed << setprecision(10) << h*sqrt(1.0*i/n) << " ";
    }
    cout << endl;
    return 0;
}
