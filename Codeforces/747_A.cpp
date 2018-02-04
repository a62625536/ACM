#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

int n;

int main()
{
    cin >> n;
    for(int i = sqrt(n);i >= 1;i--)
    {
        if(n/i*i == n)
        {
            cout << i << " " << n/i << endl;
            return 0;
        }
    }
}
