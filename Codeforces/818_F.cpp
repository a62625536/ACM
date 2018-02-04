#include<bits/stdc++.h>
using namespace std;

int q;
long long n;

int main()
{
    ios::sync_with_stdio(0);
    cin >> q;
    while(q--)
    {
        cin >> n;
        long long l = 0,r = n;
        while(l < r)
        {
            long long mid = (l+r+1)/2;
            if(n-mid < mid*(mid-1)/2)   r = mid-1;
            else    l = mid;
        }
        cout << max(n-l+l*(l-1)/2,n-(l+1)+n-(l+1)) << endl;
    }
    return 0;
}
