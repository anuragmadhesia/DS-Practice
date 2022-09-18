#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_front(8);
    cout<<"Top element is "<<dq.front()<<endl;
    cout<<"Back element is "<<dq.back()<<endl;
    dq.push_front(9);
    dq.push_back(8);
    cout<<"Top element is "<<dq.front()<<endl;
    cout<<"Back element is "<<dq.back()<<endl;
    dq.pop_front();
    cout<<"Top element is "<<dq.front()<<endl;
    cout<<"Back element is "<<dq.back()<<endl;
    cout<<"Size is "<<dq.size()<<endl;
    cout<<"is empty "<<dq.empty()<<endl;
}