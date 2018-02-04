#include<iostream>
#include<map>
#include<cstdio>
#include<string>
using namespace std;

struct node
{
    char left,right;
    friend bool operator==(node &x,node &y)
    {
        return x.left==y.left&&x.right==y.right || x.left==y.right&&x.right==y.left;
    }
};

map<char,node> mp1,mp2;
char a1[10] = {0},a2[10] = {0};
int has[128] = {0};

int main()
{
    int n,m;
    char str[10];
    scanf("%d",&n);
    getchar();
    for(int i = 0;i < n;i++)
    {
        gets(str);
        mp1[str[0]].left = str[2];
        mp1[str[0]].right = str[4];
        a1[i] = str[0];
        has[str[0]] = 1;
    }
    scanf("%d",&m);
    getchar();
    for(int i = 0;i < m;i++)
    {
        gets(str);
        mp2[str[0]].left = str[2];
        mp2[str[0]].right = str[4];
        a2[i] = str[0];
        has[str[0]] = 1;
    }
    if(m != n)  cout << "No" << endl;
    else if(m == 0 || n == 0)	cout << "Yes" << endl;
    else
    {
        int flag = 1;
        for(char i = 'A';i <= 'Z';i++)
        {	
        	if(!has[i])	continue;
        	if(mp1[i].left!= '-')	mp1[i].left = a1[mp1[i].left-'0']; 
        	if(mp1[i].right!= '-')	mp1[i].right = a1[mp1[i].right-'0']; 
        	if(mp2[i].left!= '-')	mp2[i].left = a2[mp2[i].left-'0']; 
        	if(mp2[i].right!= '-')	mp2[i].right = a2[mp2[i].right-'0']; 
            if(mp1[i] == mp2[i])    continue;
            else
            {
                flag = 0;
                break;
            }
        }
        if(flag)    cout << "Yes" << endl;
        else        cout << "No" << endl;
    }
    return 0;
}
