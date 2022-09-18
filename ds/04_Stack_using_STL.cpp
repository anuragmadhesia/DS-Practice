#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(9);
    st.push(3);
    st.emplace(6);
    cout<<"stack is empty "<<st.empty()<<endl;
    cout<<"stack top is "<<st.top()<<endl;
    cout<<"stack size is "<<st.size()<<endl;
    st.pop();
}