#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<stack>
using namespace std;

int n,vis[100005] = {0};
stack<int> s;

int main()
{
    cin >> n;
    int last = n;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        vis[x] = 1;
        while(1)
        {
            if(vis[last])
            {
                cout << last << " ";
                last--;
            }
            else    break;
        }
        cout << endl;
    }
    return 0;
}
