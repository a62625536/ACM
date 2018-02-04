#include<bits/stdc++.h>
using namespace std;

long long n;

int main()
{
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--)
    {
        cin >> n;
        int flag = 0;
        if(n == 0 || n == 1)    flag = 1;
        for(int i = 2;i <= sqrt(n);i++)
        {
            if(n%i == 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag)    cout << "No" << endl;
        else    cout << "Yes" << endl;
    }
    return 0;
}
