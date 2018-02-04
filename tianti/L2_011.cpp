#include<bits/stdc++.h>
using namespace std;

int n,a[35],b[35];
struct xx
{
    int x;
    xx *l,*r;
}*root;

void f(int l,int r,int now,xx *&p)
{
    if(l > r)   return;
    p = new xx;
    p->x = b[now];
    p->l = NULL;
    p->r = NULL;
    int t = l;
    while(a[t] != b[now])   t++;
    f(l,t-1,now+1,p->r);
    f(t+1,r,now+t-l+1,p->l);
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1;i <= n;i++)   cin >> a[i];
    for(int i = 1;i <= n;i++)   cin >> b[i];
    root = NULL;
    f(1,n,1,root);
    queue<xx*> q;
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
