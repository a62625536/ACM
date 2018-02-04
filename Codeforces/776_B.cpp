#include<bits/stdc++.h>
using namespace std;

int n,vis[100005] = {0};

int main()
{
    cin >> n;
    if(n <= 2)
    {
        cout << 1 << endl;
        for(int i = 1;i <= n;i++)   cout << 1 << " ";
        cout << endl;
        return 0;
    }
    n++;
    cout << 2 << endl;
    for(int i = 2;i <= n;i++)
    {
        if(vis[i])  cout << 2 << " ";
        else
        {
            cout << 1 << " ";
            for(int j = i;j <= n;j += i)    vis[j] = 1;
        }
    }
    return 0;
}
