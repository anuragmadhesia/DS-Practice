// You are given an array arr[ ], of n integers.
//  Minimize the max difference between the pairs of adjacent array elements by inserting at most k
//   elements in the array.

#include <bits/stdc++.h>
#define MAXN 100000
using namespace std;

int minimizedMaxDiff(int arr[], int n, int k);

int main()
{
    int arr[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> arr[i];
        
        int k;
        cin>>k;
        
        cout<< minimizedMaxDiff(arr,n,k) << endl;
    }
    return 1;
}
// } Driver Code Ends


//User function Template for C++

int insertions(int arr[], int n, int gap)
{
    int ret=0;
    for(int i=1; i<n; i++)
        if( arr[i] != arr[i-1] )
            ret += ( abs(arr[i]-arr[i-1]) -1 ) / gap;
    return ret;
}

int minimizedMaxDiff(int arr[], int n, int k)
{
    int low=1, high=1;
    for(int i=1; i<n; i++)
        high = max( high , abs(arr[i] - arr[i-1]) );
    
    while(high>low)
    {
        int mid = (high+low)/2;
        
        if( insertions(arr,n,mid) <= k )
            high = mid;
        else
            low = mid+1;
    }
    
    return high;
}
