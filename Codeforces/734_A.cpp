#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;
    int sum1 = 0,sum2 = 0;
    for(int i = 0;i < n;i++)
    {
        if(s[i] == 'A') sum1++;
        else    sum2++;
    }
    if(sum1 > sum2) cout << "Anton" << endl;
    else if(sum1 < sum2)    cout << "Danik" << endl;
    else    cout << "Friendship" << endl;
    return 0;
}
