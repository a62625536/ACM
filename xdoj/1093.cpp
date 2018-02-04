#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
const double eps=0.0001;
double a,b,c,d;

double ans[5];
int sum;

inline double calc(double x)
{
    return a*x*x*x+b*x*x+c*x+d;
}

inline void find(double l,double r)
{
    if(r-l <= eps)
	{
        ans[++sum] = (l+r)/2;
        return;
    }
    double mid = (l+r)/2,tmp = calc(mid),tmpl = calc(l),tmpr = calc(r);
    if(abs(tmp) < eps)
	{
        ans[++sum] = mid;
        return;
    }
    if(tmp*tmpl < 0)
	{
        find(l,mid);
        return;
    }
	find(mid,r);
}

int main()
{
    while(~scanf("%lf%lf%lf%lf",&a,&b,&c,&d))
    {
    	sum = 0;
    	for(int i=-101;i<=101;i++)
		{
	        double tmp1 = calc(i),tmp2 = calc(i+1);
	        if(abs(tmp1) < eps)	ans[++sum] = i;
	        else if(abs(tmp2) < eps)
			{
	            ans[++sum] = i+1;
	            i++;
	        }
	        else if(tmp1*tmp2 < 0)	find(i,i+1);
	        if(sum == 3)	break;
    	}
    	sort(ans+1,ans+4);
	    printf("%.2lf %.2lf %.2lf\n",ans[1],ans[2],ans[3]);
	}
    return 0;
}

