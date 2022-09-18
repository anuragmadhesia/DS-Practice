// https://www.geeksforgeeks.org/sum-of-bit-differences-among-all-pairs/
#include <bits/stdc++.h>
using namespace std;

long long sumBitDiff(int arr[], int n) ;
  
int main()
{
	int t;
    cin>>t;
    while(t--)
    {
    	int n,i;
    	cin>>n;
    	int arr[n];
    	for(i=0;i<n;i++)
    		cin>>arr[i];
		cout<<sumBitDiff(arr,n)<<endl;
    }
	return 0; 
}
// } Driver Code Ends


//User function Template for C++
long long sumBitDiff(int arr[], int n) 
{ 
    long long ans = 0;  // Initialize result 
  
    // traverse over all bits 
    for (int i = 0; i < 32; i++) 
    { 
        // count number of elements with i'th bit set 
        int count = 0; 
        for (int j = 0; j < n; j++) 
            if ( (arr[j] & (1 << i)) ) 
                count++; 
  
        // Add "count * (n - count) * 2" to the answer 
        ans += (count * (n - count) * 2); 
    } 
  
    return ans; 
}