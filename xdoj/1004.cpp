#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[15],b[15],A,B,C,D,E,F,G,H,I,J;
int point[12][2] = {{1,12},{2,7},{3,8},{4,9},{5,10},{6,11},{7,2},{8,3},{9,4},{10,5},{11,6},{12,1}};
int x[12][10] = {{2,3,4,5,6,10,11,7,8,9},{1,6,9,10,3,5,8,12,11,4},{11,4,1,2,10,7,5,6,9,12},{1,3,11,7,5,2,10,12,8,6},
				 {1,4,7,8,6,3,11,12,9,2},{1,5,8,9,2,4,7,12,10,3},{4,11,12,8,5,3,10,9,6,1},{12,9,6,5,7,10,2,1,4,11},
				 {6,8,12,10,2,5,7,11,3,1},{2,9,12,11,3,6,8,7,4,1},{3,10,12,7,4,2,9,8,5,1},{9,8,7,11,10,6,5,4,3,2}};

int fun(int AA,int BB,int CC,int DD,int EE,int FF,int GG,int HH,int II,int JJ)
{
	if(AA==A && BB==B && CC==C && DD==D && EE==E && FF==F && GG==G && HH==H && II==I && JJ==J)	return 1;
	if(AA==B && BB==C && CC==D && DD==E && EE==A && FF==G && GG==H && HH==I && II==J && JJ==F)	return 1;
	if(AA==C && BB==D && CC==E && DD==A && EE==B && FF==H && GG==I && HH==J && II==F && JJ==G)	return 1;
	if(AA==D && BB==E && CC==A && DD==B && EE==C && FF==I && GG==J && HH==F && II==G && JJ==H)	return 1;
	if(AA==E && BB==A && CC==B && DD==C && EE==D && FF==J && GG==F && HH==G && II==H && JJ==I)	return 1;
	return 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int flag = 1;
		for(int i = 1;i <= 12;i++)	scanf("%d",&a[i]);
		for(int i = 1;i <= 12;i++)	scanf("%d",&b[i]);
		A = b[2],B = b[3],C = b[4],D = b[5],E = b[6];
		F = b[10],G = b[11],H = b[7],I = b[8],J = b[9];
		for(int i = 0;i < 12;i++)
		{
			if(a[point[i][0]] == b[1] && a[point[i][1]] == b[12])
			{
				if(fun(a[x[i][0]],a[x[i][1]],a[x[i][2]],a[x[i][3]],a[x[i][4]],
					a[x[i][5]],a[x[i][6]],a[x[i][7]],a[x[i][8]],a[x[i][9]]))
				{
					flag = 0;
					printf("Identical\n");
					break;
				}	
			}
		}
		if(flag)	printf("Different\n");
	}
	return 0;
} 
