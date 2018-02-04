#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

int main()
{
    cin >> n;
    int sum = 0,maxx = 0;
    for(int i = 1;i <= n;i++)
    {
        int x;
        cin >> x;
        maxx = max(maxx,x);
        sum += x;
    }
    cout << maxx*n-sum << endl;
    return 0;
}
