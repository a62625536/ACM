#include<bits/stdc++.h>
using namespace std;

int n,a[35],b[35];
struct xx
{
    int x;
    xx *l,*r;
}*root;

queue<xx*> q;
void f(int l,int r,int now,xx *&p)
{
    if(l > r)   return;
    int t = l;
    while(b[t] != a[now])   t++;
    p = new xx;
    p->x = a[now];
    p->l = NULL;
    p->r = NULL;
    f(l,t-1,now-r+t-1,p->l);
    f(t+1,r,now-1,p->r);
}

int main()
{
    ios::sync_with_stdio(false);
    root = NULL;
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)   cin >> b[i];
    f(1,n,n,root);
    cout << root->x;
    if(root->l) q.push(root->l);
    if(root->r) q.push(root->r);
    while(!q.empty())
    {
        xx *t = q.front();
        q.pop();
        cout << " " << t->x;
        if(t->l)    q.push(t->l);
        if(t->r)    q.push(t->r);
    }
    cout << endl;
    return 0;
}
