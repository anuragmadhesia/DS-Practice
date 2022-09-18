// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

string smallestK(long long n);

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
        long long n;
        cin>>n;
        cout<< smallestK(n) << endl;
	}
	return 1;
}
// } Driver Code Ends


//User function Template for C++

string smallestK(long long n)
{
    if(n==1) return "1";
    
    int count[10];
    for(int i=0; i<10; i++)
        count[i]=0;
    
    for(int divisor=9; divisor>1; divisor--)
        while(n%divisor == 0)
        {
            count[divisor]++;
            n=n/divisor;
        }
    
    if(n>1) return "-1";
    
    string ret;
    for(int divisor=2; divisor<10; divisor++)
        while(count[divisor]--)
            ret.push_back('0'+divisor);
    
    return ret;
}
