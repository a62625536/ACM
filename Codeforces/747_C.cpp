#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

struct ss
{
    int id,t;
    ss(int x,int y):id(x),t(y){};
    friend bool operator <(ss a,ss b)
    {
        return a.t > b.t;
    }
};
int n,q;
priority_queue<ss> q1;
priority_queue< int,vector<int>,greater<int> > q2;

int main()
{
    cin >> n >> q;
    for(int i = 1;i <= n;i++)   q2.push(i);
    while(q--)
    {
        int t,k,d;
        cin >> t >> k >> d;
        while(!q1.empty())
        {
            if(q1.top().t > t)  break;
            q2.push(q1.top().id);
            q1.pop();
        }
        if(q2.size() < k)   cout << -1 << endl;
        else
        {
            int sum = 0;
            while(k--)
            {
                sum += q2.top();
                q1.push(ss(q2.top(),t+d));
                q2.pop();
            }
            cout << sum << endl;
        }
    }
    return 0;
}
