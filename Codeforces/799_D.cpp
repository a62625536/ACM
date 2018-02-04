#include <bits/stdc++.h>
using namespace std;

int a,b,w,h,n,A[100005],ans;

void dfs(int x,int y,int now,int nowx,int nowy)
{
    if(nowx >= x && nowy >= y)
    {
        ans = min(ans,now);
        return;
    }
    if(now == n+1)    return;
    if(A[now] == 2)
    {
        while(x > nowx)
        {
            nowx *= 2;
            now++;
        }
        while(y > nowy)
        {
            nowy *= 2;
            now++;
        }
        ans = min(ans,now);
        return;

    }
    if(x > nowx)    dfs(x,y,now+1,nowx*A[now+1],nowy);
    if(y > nowy)    dfs(x,y,now+1,nowx,nowy*A[now+1]);
}
int main()
{
    ios::sync_with_stdio(false);
	cin >> a >> b >> w >> h >> n;
	for(int i = 1;i <= n;i++)   cin >> A[i];
	sort(A+1,A+1+n);
	reverse(A+1,A+1+n);
	ans = n+1;
	dfs((a-1)/h+1,(b-1)/w+1,0,1,1);
	dfs((a-1)/w+1,(b-1)/h+1,0,1,1);
	if(ans == n+1)  cout << -1 << endl;
	else    cout << ans << endl;
	return 0;
}
