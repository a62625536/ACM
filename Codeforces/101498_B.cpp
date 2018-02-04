#include<bits/stdc++.h>
using namespace std;

char a[100005],b[100005];
int cnt[128];

int main()
{
    ios::sync_with_stdio(0);
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s%s",a,b);
        memset(cnt,0,sizeof(cnt));
        int len1 = strlen(a),len2 = strlen(b);
        for(int i = 0;i < len2;i++) cnt[b[i]]++;
        int ans = 0;
        for(int i = 0;i < len1;i++)
        {
            if(!cnt[a[i]]) break;
            ans++;
            cnt[a[i]]--;
        }
        printf("%d\n",ans);
    }
    return 0;
}
