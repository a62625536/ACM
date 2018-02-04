#include<bits/stdc++.h>
using namespace std;

int n,now,x;

int main()
{
    ios::sync_with_stdio(0);
    srand(time(0));
    cin >> n >> now >> x;
    cout << "? " << now << endl;
    int ne;
    cin >> now >> ne;
    if(now >= x)
    {
        cout << "! " << now << endl;
        return 0;
    }
    for(int i = 1;i <= 1000;i++)
    {
        long long t = (long long)rand()*rand()%n+1;
        cout << "? " << t << endl;
        int v,vv;
        cin >> v >> vv;
        if(v < x && v > now)
        {
            now = v;
            ne = vv;
        }
    }
    while(ne != -1)
    {
        cout << "? " << ne << endl;
        cin >> now >> ne;
        if(now >= x)
        {
            cout << "! " << now << endl;
            return 0;
        }
    }
    cout << "! -1" << endl;
    return 0;
}
