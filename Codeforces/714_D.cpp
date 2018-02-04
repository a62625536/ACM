#include<bits/stdc++.h>
using namespace std;

int n;
struct xx
{
    long long x1,x2,y1,y2;
    void print()
    {
        cout << x1 << " " << y1 << " " << x2 << " " << y2 << " ";
    }
};

int query(int x1,int y1,int x2,int y2)
{
    if(x1 > x2)swap(x1,x2);
    if(y1 > y2)swap(y1,y2);
    cout<<"? "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    int ans;
    cin>>ans;
    return ans;
}

xx f(int x1,int y1,int x2,int y2)
{
    xx ans;
    long long l = x1,r = x2;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(query(x1,y1,mid,y2) < 1) l = mid+1;
        else    r = mid;
    }
    ans.x2 = l;
    l = x1,r = x2;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(query(mid,y1,x2,y2) < 1) r = mid-1;
        else    l = mid;
    }
    ans.x1 = l;
    l = y1,r = y2;
    while(l < r)
    {
        int mid = (l+r)/2;
        if(query(x1,y1,x2,mid) < 1) l = mid+1;
        else    r = mid;
    }
    ans.y2 = l;
    l = y1,r = y2;
    while(l < r)
    {
        int mid = (l+r+1)/2;
        if(query(x1,mid,x2,y2) < 1) r = mid-1;
        else    l = mid;
    }
    ans.y1 = l;
    return ans;
}
int main()
{
    cin >> n;
    long long x1,y1,x2,y2,x3,y3,x4,y4;
    long long l = 1,r = n;
    while(l < r)
    {
        long long mid = (l+r)/2;
        if(query(1,1,mid,n) < 1)    l = mid+1;
        else    r = mid;
    }
    long long t = l;
    if(query(1,1,t,n) == 1 && query(t+1,1,n,n) == 1)
    {
        xx a = f(1,1,t,n),b = f(t+1,1,n,n);
        cout << "! ";
        a.print();
        b.print();
        cout << endl;
        return 0;
    }
    l = 1,r = n;
    while(l < r)
    {
        long long mid = (l+r)/2;
        if(query(1,1,n,mid) < 1)    l = mid+1;
        else    r = mid;
    }
    t = l;
    xx a = f(1,1,n,t),b = f(1,t+1,n,n);
    cout << "! ";
    a.print();
    b.print();
    cout << endl;
    return 0;
}

