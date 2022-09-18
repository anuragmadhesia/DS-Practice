#include <bits/stdc++.h>
using namespace std;
#define bool int

/* Function to check if x is power of 2*/
bool isPowerOfTwo (int x)
{
	/* First x in the below expression is for the case when x is 0 */
	return x && (!(x&(x-1)));
}

/*Driver code*/
int main()
{
	isPowerOfTwo(31)? cout<<"Yes\n": cout<<"No\n";
	isPowerOfTwo(64)? cout<<"Yes\n": cout<<"No\n";
	isPowerOfTwo(0)? cout<<"Yes\n": cout<<"No\n";
	isPowerOfTwo(1)? cout<<"Yes\n": cout<<"No\n";
	isPowerOfTwo(4)? cout<<"Yes\n": cout<<"No\n";
	return 0;
}

// This code is contributed by rathbhupendra
