#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;

queue<int> qd,qr;
int n;
string s;

int main()
{
    cin >> n >> s;
    for(int i = 0; i < s.length();i++)
    {
        if(s[i] == 'D') qd.push(i);
        else    qr.push(i);
    }
    while(!qd.empty() && !qr.empty())
    {
        if(qd.front() < qr.front())
        {
            qd.push(qd.front()+n);
            qd.pop();
            qr.pop();
        }
        else
        {
            qr.push(qr.front()+n);
            qr.pop();
            qd.pop();
        }
    }
    if(!qd.empty()) cout << "D" << endl;
    else    cout << "R" << endl;
    return 0;
}
