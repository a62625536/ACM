#include<bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    int ans = 0;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin >> s;
        if(s == "Tetrahedron")  ans += 4;
        if(s == "Cube") ans += 6;
        if(s == "Octahedron")   ans += 8;
        if(s == "Dodecahedron") ans += 12;
        if(s == "Icosahedron")  ans += 20;
    }
    cout << ans << endl;
    return 0;
}