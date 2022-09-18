#include<iostream>
#include<queue>

using namespace std;

int main(){
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(7);
    pq.push(8);
    pq.push(3);
    pq.push(99);
    pq.push(33);
    cout<<"isEmpty ? "<<pq.empty()<<endl;
    cout<<"Size of heap : "<<pq.size()<<endl;
    cout<<"Min element : "<<pq.top()<<endl;
    pq.pop();
    cout<<"Min element : "<<pq.top()<<endl;
}