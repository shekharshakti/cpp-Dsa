#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int size;
    int top;
    stack(int size){
        arr=new int [size];
        this->size=size;
        this->top=-1;

    }
    void push(int data){
        if(top==size-1){
            cout<<"stackOverflow"<<endl;
            return;
        }else{
            top++;
            arr[top]=data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stackUnderflow"<<endl;
            return;
        }else{
            top--;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }else{
            return false;
        }
    }
    int getTop(){
        if(top==-1){
            cout<<"stack is empty"<<endl;
            return -1;
        }else{
           return arr[top];
            }
    }
    int getSize(){
        return top+1;
    }
    void print(){
        cout<<"top"<<top<<endl;
        cout<<"topElement:-"<<getTop()<<endl;
        cout<<"stack:- ";
        for(int i=0;i<getSize();i++){
            cout<<arr[i]<<" ";

        }cout<<endl<<endl;
    }

};
int main(){
    stack st(8);
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    st.print();



    st.pop();
    st.pop();
    st.print();
    return 0;


}