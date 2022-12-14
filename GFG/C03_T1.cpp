// { Driver Code Starts
//Initial Template for C++
// Given two strings A and B, find the minimum number of times A has to be stated such that B becomes
//  a substring of the repeated A. If no such solution exists, return -1.
#include <bits/stdc++.h>
using namespace std;
int repeatedStringMatch(string A, string B);


 // } Driver Code Ends


//User function Template for C++
bool isSubString(string s, string sub) {
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == sub[count]){
            count++;
        } else {
            i-=count;
            count = 0;
        }
        if (count == sub.length()) {
            return true;
        }
    }
    return false;
}

int repeatedStringMatch(string A, string B) {
    string temp = A;
    int count = ceil(float(B.length()) / float(A.length()));

    for(int i=1; i<count; i++)
        A += temp;
    
    if(isSubString(A,B))
        return count;
    else
    {
        A += A;
        if(isSubString(A,B))
            return count+1;
    }
    return -1;
}


// { Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string A,B;
        cin>>A;
        cin>>B;
        cout<<repeatedStringMatch(A,B)<<"\n";
    }
    return 0;
}
  // } Driver Code Ends