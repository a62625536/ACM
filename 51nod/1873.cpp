#include<bits/stdc++.h>
using namespace std;

int n;
string a;

string mul(string a,string b)
{
    int arr[200],len = a.length()+b.length();
    memset(arr,0,sizeof(arr));
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i = 0;i < a.length();i++)
    {
        for(int j = 0;j < b.length();j++)   arr[i+j] += (a[i]-'0')*(b[j]-'0');
    }
    for(int i = 0;i < len;i++)
    {
        arr[i+1] += arr[i]/10;
        arr[i] %= 10;
    }
    string ans = string(len,'0');
    for(int i = 0;i < len;i++)  ans[i] += arr[i];
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return ans;
}

string Str_Pow(string x,int b)
{
    string ans = "1";
    while(b)
    {
        if(b%2) ans = mul(ans,x);
        x = mul(x,x);
        b /= 2;
    }
    return ans;
}
int main()
{
    cin >> a >> n;
    int index = a.find('.');
    if(index == -1) index = 0;
    else
    {
        a = a.substr(0,index)+a.substr(index+1);
        index = (a.length()-index)*n;
    }
    a = Str_Pow(a,n);
    a = a.substr(0,a.length()-index)+"."+a.substr(a.length()-index);
    int i;
    for(i = 0;a[i] == '0';i++);
    a = a.substr(i);
    for(int i = a.length()-1;i >= 0;i--)
    {
        if(a[i] == '.')
        {
            a = a.substr(0,i);
            break;
        }
        else if(a[i] != '0')
        {
            a = a.substr(0,i+1);
            break;
        }
    }
    cout << a << endl;
    return 0;
}
