#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
#include<cmath>
using namespace std;

int compare(string str1,string str2)
{
    if(str1.length() > str2.length())	return 1;
    else if(str1.length() < str2.length())	return -1;
    else	return str1.compare(str2);
}

string sub(string str1,string str2)//¼õ·¨
{
    string str;
    int flag = 0;
    if(compare(str1,str2) < 0)
    {
        flag = 1;
        swap(str1,str2);
    }
    int tmp = str1.length()-str2.length(),cf = 0;
    for(int i = str2.length()-1;i >= 0;i--)
    {
        if(str1[tmp+i] < str2[i]+cf)
        {
            str = char(str1[tmp+i]-str2[i]-cf+'0'+10)+str;
            cf = 1;
        }
        else
        {
            str = char(str1[tmp+i]-str2[i]-cf+'0')+str;
            cf = 0;
        }
    }
    for(int i = tmp-1;i >= 0;i--)
    {
        if(str1[i]-cf >= '0')
        {
            str = char(str1[i]-cf)+str;
            cf = 0;
        }
        else
        {
            str = char(str1[i]-cf+10)+str;
            cf = 1;
        }
    }
    str.erase(0,str.find_first_not_of('0'));
    if(str.empty())   str = "0";
    if(flag)    str = "-"+str;
    return str;
}

string add(string str1,string str2)//¼Ó·¨
{
    string str;
    int len1 = str1.length(),len2 = str2.length();
    if(len1 < len2)
    {
        for(int i = 1;i <= len2-len1;i++)	str1 = "0"+str1;
    }
    else
    {
        for(int i = 1;i <= len1-len2;i++)	str2 = "0"+str2;
    }
    int cf = 0,temp;
    for(int i = str1.length()-1;i >= 0;i--)
    {
        temp = str1[i]-'0'+str2[i]-'0'+cf;
        cf = temp/10;
        temp %= 10;
        str = char(temp+'0')+str;
    }
    if(cf != 0)	str = char(cf+'0')+str;
    return str;
}


int main()
{
     string a,b;
     cin >> a >> b;
     if(a[0] == '-' && b[0] == '-')
     {
         a.erase(a.begin());
         b.erase(b.begin());
         cout << '-' << add(a,b) << endl;
     }
     else if(a[0] == '-')
     {
         a.erase(a.begin());
         cout << sub(b,a) << endl;
     }
     else if(b[0] == '-')
     {
         b.erase(b.begin());
         cout << sub(a,b) << endl;
     }
     else   cout << add(a,b) << endl;
     return 0;
}
