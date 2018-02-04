#include<bits/stdc++.h>
using namespace std;

int n;
set<int> s;
set<int>::iterator it;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        it = s.lower_bound(x);
        if(it == s.end())   s.insert(x);
        else
        {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size() << endl;
    return 0;
}
