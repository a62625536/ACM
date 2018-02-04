#include<bits/stdc++.h>
using namespace std;

int n,a[10] = {0},b[10] = {0};

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        b[x]++;
    }
    int x = 0,y = 0,flag = 0;
    for(int i = 1;i <= 5;i++)
    {
        if(a[i] > b[i])
        {
            int t = a[i]-b[i];
            if(t%2)
            {
                flag = 1;
                break;
            }
            x += t/2;
        }
        else if(b[i] > a[i])
        {
            int t = b[i]-a[i];
            if(t%2)
            {
                flag = 1;
                break;
            }
            y += t/2;
        }
    }
    if(x != y || flag)  cout << -1 << endl;
    else    cout << x << endl;
    return 0;
}
