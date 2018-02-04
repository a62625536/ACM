#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int n;

bool isprime(int x)
{
    if(x == 1)  return 0;
    if(x == 2)  return 1;
    for(int i = 2;i*i <= x;i++)
    {
        if(x%i == 0)    return 0;
    }
    return 1;
}

int main()
{
    cin >> n;
    if(isprime(n))  printf("1\n");
    else if(n%2 == 0)    printf("2\n");
    else if(isprime(n-2))   printf("2\n");
    else    printf("3\n");
    return 0;
}
