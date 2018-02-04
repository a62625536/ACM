#include <bits/stdc++.h>
using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);
	while(cin >> n)
    {
        if(n <= 1000)   cout << "XiaoZhen" << endl;
        else if(n < 10000)  cout << "Zh0ngshen" << endl;
        else    cout << "DaNuo" << endl;
    }
	return 0;
}
