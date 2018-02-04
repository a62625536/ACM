#include<bits/stdc++.h>
using namespace std;

int a,b,n;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> a >> b >> n;
    int x = 0,y = 0;
    for(int i = 1;i <= n;i++)
    {
        int aaa,aa,bbb,bb;
        cin >> aaa >> aa >> bbb >> bb;
        if(aaa+bbb == aa && aaa+bbb == bb)  continue;
        else if(aaa+bbb == aa)
        {
            x++;
            if(x > a)
            {
                cout << "A" << endl;
                cout << y << endl;
                return 0;
            }
        }
        else if(aaa+bbb == bb)
        {
            y++;
            if(y > b)
            {
                cout << "B" << endl;
                cout << x << endl;
                return 0;
            }
        }
    }
    return 0;
}
