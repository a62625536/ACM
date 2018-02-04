#include<bits/stdc++.h>
using namespace std;

long long ax,ay,bx,by,cx,cy;

int main()
{
    ios::sync_with_stdio(0);
    cin >> ax >> ay >> bx >> by >> cx >> cy;
    if((ay-by)*(bx-cx) == (by-cy)*(ax-bx) || (ay-by)*(ay-by)+(ax-bx)*(ax-bx) != (by-cy)*(by-cy)+(bx-cx)*(bx-cx))    cout << "No" << endl;
    else    cout << "Yes" << endl;
    return 0;
}


