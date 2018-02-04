#include<bits/stdc++.h>
using namespace std;

string s1,s2;

int main()
{
    ios::sync_with_stdio(false);
    cin >> s1;
    sort(s1.begin(),s1.end());
    cin >> s2;
    sort(s2.begin(),s2.end());
    reverse(s2.begin(),s2.end());
    int n = (s1.length()+1)/2,m = s1.length()/2;
    int now1 = 0,now2 = 0;
    char ans[300005] = {0};
    int num = 0,l = 0,r = s1.length()-1;
    while(num < s1.length() && s1[now1] < s2[now2])
    {
        if(num%2 == 0)  ans[l++] = s1[now1++];
        else    ans[l++] = s2[now2++];
        num++;
    }
    now1 = n-1,now2 = m-1;
    while(num < s1.length())
    {
        if(num%2 == 0)  ans[r--] = s1[now1--];
        else    ans[r--] = s2[now2--];
        num++;
    }
    cout << ans << endl;
    return 0;
}
