#include<bits/stdc++.h>
using namespace std;

int a,b;
char s;

int main()
{
    std::ios::sync_with_stdio(false);
    scanf("%d%c%d",&a,&s,&b);
    if(0 <= a && a <= 11 || a == 12 && b == 0)
    {
        printf("Only %02d:%02d.  Too early to Dang.\n",a,b);
        return 0;
    }
    if(b != 0)  a++;
    a -= 12;
    while(a--)  printf("Dang");
    printf("\n");
    return 0;
}
