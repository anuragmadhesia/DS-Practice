// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function template for C++


class Solution{
public:
    void rearrange(vector<int>& array, int n)
    {
        for(int i = 0;i<n;i++){
            array[i] = array[i] + (array[array[i]]%n) * n;
        }

        for(int i = 0;i<n;i++)
            array[i] = array[i]/n;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> array(n);
        for(int i = 0 ;i<n;i++){
            cin>>array[i];
        }
        Solution ob;
        ob.rearrange(array,n);
        for(int i = 0 ;i<n;i++){
            cout<<array[i]<<" ";
        }
        cout<<"\n";
    }
}  // } Driver Code Ends