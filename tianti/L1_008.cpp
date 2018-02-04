#include<bits/stdc++.h>
using namespace std;

int l,r;

int main()
{
    std::ios::sync_with_stdio(false);
    cin >> l >> r;
    int now = 0,sum = 0;
    for(int i = l;i <= r;i++)
    {
        cout << setw(5) << right << i;
        now++;
        if(now == 5)
        {
            cout << endl;
            now = 0;
        }
        sum += i;
    }
    if(now != 0)    cout << endl;
    cout << "Sum = " << sum << endl;
    return 0;
}
