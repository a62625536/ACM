#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n;

int main()
{
    scanf("%d",&n);
    if(n%2) printf("black");
    else    printf("white\n1 2\n");
    return 0;
}
