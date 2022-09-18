#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    q.push(3);
    cout<<q.front()<<endl;
    q.push(5);
    cout<<q.front()<<endl;
    cout<<"isEmpty? "<<q.empty()<<endl;
    cout<<"Size is "<<q.size()<<endl;
    q.pop();q.pop();
}