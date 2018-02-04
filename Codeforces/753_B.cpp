#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[5];

int main()
{
    int cnt,x,y;
    for(int i = 0;i <= 9;i++)
    {
        cout << i << i << i << i << endl;
        cin >> x >> y;
        if(x)   a[cnt++] = i;
    }
    cout << a[0] << a[1] << a[2] << a[3] << endl;
    cin >> x >> y;
    while(x != 4)
    {
        next_permutation(a,a+4);
        cout << a[0] << a[1] << a[2] << a[3] << endl;
        cin >> x >> y;
    }
    return 0;
}
