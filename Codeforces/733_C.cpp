#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n,k,a[505],b[505],ans[505];
char c[505];

int main()
{
    int sum1 = 0,sum2 = 0,cnt = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d",&a[i]);
        sum1 += a[i];
    }
    scanf("%d",&k);
    for(int i = 1;i <= k;i++)
    {
        scanf("%d",&b[i]);
        sum2 += b[i];
    }
    if(sum1 != sum2)
    {
        printf("NO\n");
        return 0;
    }
    int r = n,l = r;
    for(int i = k;i >= 1;i--)
    {
        for(;l >= 1;l--)
        {
            if(b[i] > a[l])    b[i] -= a[l];
            else if(b[i] < a[l])
            {
                printf("NO\n");
                return 0;
            }
            else
            {
                if(l != r)
                {
                    int maxx = a[r],t,flag = 1;
                    for(int j = r;j >= l;j--)
                    {
                        if(maxx != a[j])    flag = 0;
                        maxx = max(maxx,a[j]);
                    }
                    if(flag)
                    {
                        printf("NO\n");
                        return 0;
                    }
                    for(int j = r;j >= l;j--)
                    {
                        if(maxx != a[j])    continue;
                        if(j == r && a[r-1] != maxx)
                        {
                            flag = 1;
                            for(int h = r;h > l;h--)
                            {
                                cnt++;
                                ans[cnt] = h;
                                c[cnt] = 'L';
                            }
                            break;
                        }
                        else if(j == l && a[l+1] != maxx)
                        {
                            flag = 1;
                            for(int h = l;h < r;r--)
                            {
                                cnt++;
                                ans[cnt] = h;
                                c[cnt] = 'R';
                            }
                            break;
                        }
                        else if(j != r && a[j+1] != maxx)
                        {
                            flag = 1;
                            int h;
                            for(h = j;h < r;r--)
                            {
                                cnt++;
                                ans[cnt] = h;
                                c[cnt] = 'R';
                            }
                            for(;h > l;h--)
                            {
                                cnt++;
                                ans[cnt] = h;
                                c[cnt] = 'L';
                            }
                            break;
                        }
                        else if(j != l && a[j-1] != maxx)
                        {
                            flag = 1;
                            int h;
                            for(h = j;h > l;h--,r--)
                            {
                                cnt++;
                                ans[cnt] = h;
                                c[cnt] = 'L';
                            }
                            for(;h < r;r--)
                            {
                                cnt++;
                                ans[cnt] = h;
                                c[cnt] = 'R';
                            }
                            break;
                        }
                    }
                    if(!flag)
                    {
                        printf("NO\n");
                        return 0;
                    }
                }
                l--;
                r = l;
                break;
            }
        }
    }
    printf("YES\n");
    for(int i = 1;i <= cnt;i++) printf("%d %c\n",ans[i],c[i]);
    return 0;
}
