#include<bits/stdc++.h>
using namespace std;

double n,m;

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        double t = (n-100)*1.8;
        if(m < t && t-m > t*0.1-1e-7)    cout << "You are tai shou le!" << endl;
        else if(t < m && m-t > t*0.1-1e-7)   cout << "You are tai pang le!" << endl;
        else    cout << "You are wan mei!" << endl;
    }
    return 0;
}
