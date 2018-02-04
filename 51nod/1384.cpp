#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

char a[10];

int main()
{
    scanf("%s",a);
    int l = strlen(a);
    sort(a,a+l);
    puts(a);
    while(next_permutation(a,a+l))  puts(a);
    return 0;
}
