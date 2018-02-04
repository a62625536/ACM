#include<cstdio>
#include<iostream>
#include<stack>
using namespace std;
int a[1005];
int main()
{
    stack<int> s;
    int limit,n,num;
    cin >> limit >> n >> num;
    while(num--)
    {
        while(!s.empty())   s.pop();
        for(int i = 1;i <= n;i++)   cin >> a[i];
        int flag = 1,in = 1,out = 1;
        while(out <= n)
        {
            if(s.size() > limit)
            {
                flag = 0;
                break;
            }
            if(!s.empty() && s.top() == a[out])
            {
                s.pop();
                out++;
            }
            else if(a[out] >= in)
            {
                s.push(in++);
            }
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag)    cout << "YES" << endl;
        else    cout << "NO" << endl;
    }
    return 0;
}
