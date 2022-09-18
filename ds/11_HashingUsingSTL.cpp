#include<iostream>
#include <set> 
#include<map>

using namespace std;

int main(){
    map<int,int> mp;
    map<int,int>::iterator it;
    // empty set container
    set <int> s;
    // List of elements
    int arr[] = {40, 20, 60, 30, 50, 50, 10};
    // Insert the elements of the List
    // to the set
    for(int i = 0; i < 7; i++)
        s.insert(arr[i]);
    // Print the content of the set
    // The elements of the set will be sorted
    // without any duplicates
    cout<<"The elements in the set are: \n";
    for(auto itr=s.begin(); itr!=s.end(); itr++)
    {
        cout<<*itr<<" ";
    }
    mp[10]=56;
    mp[2]=434;
    mp[0]=-23;
    mp[-3]=67;
    mp[-34]=-34;
    cout<<"\nSize of map : "<<mp.size()<<endl;
    for(it=mp.begin();it!=mp.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    // Check if 50 is present in the set
    if(mp.find(50)!=mp.end())
    {
        cout<<"\n\n50 is present";
    }
    else
    {
        cout<<"\n\n50 is not present";
    }
}