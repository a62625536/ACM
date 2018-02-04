#include <iostream>
using namespace std;

long long l1,l2,r1,r2,k;
 
int main()
{
   	cin >> l1 >> r1 >> l2 >> r2 >> k;
   	long long l = max(l1,l2),r = min(r1,r2);
   	if(l > r)	cout << 0 << endl;
   	else
   	{
   		long long t = r-l+1;
   		if(l <= k && k <= r)	t--;
   		cout << t << endl;
	}
    return 0;
}
