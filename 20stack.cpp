#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int>st;

    st.push(10);
    st.push(15);
    st.push(30);
    st.push(45);
    cout<<"size of stack is:-"<<st.size()<<endl;
    st.pop();
    cout<<"size of stack is:-"<<st.size()<<endl;
    cout<<"top eleement is:-"<<st.top()<<endl;
    if(st.empty()){
        cout<<"stck is empty"<<endl;

    }else{
        cout<<"stack is non empty "<<endl;
    }

    string str="helloShekhar";
    stack<char>she;
    for(int i=0;i<str.length();i++){
        char ch=str[i];
        she.push(ch);
    }
    cout<<endl;
    while(!she.empty()){
        cout<<she.top();
        she.pop();
    }cout<<endl;
}