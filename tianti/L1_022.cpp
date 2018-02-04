#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> n;
    int a = 0,b = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        if(x&1) a++;
        else    b++;
    }
    cout << a << " " << b << endl;
    return 0;
}
