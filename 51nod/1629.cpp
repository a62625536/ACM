#include<bits/stdc++.h>
#define PI acos(-1)
using namespace std;

double s;

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    double t = sqrt(s/PI);
    cout << fixed << setprecision(10) << sqrt(2)/12*PI*t*t*t << endl;
    return 0;
}
