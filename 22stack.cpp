#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    int *arr;
    int size;
    int top1;
    int top2;

public:
    Stack(int size) {
        this->size = size;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int data) {
        if (top1 + 1 == top2) {
            cout << "Stack 1 Overflow!" << endl;
            return;
        }
        arr[++top1] = data;
    }

    void push2(int data) {
        if (top2 - 1 == top1) {
            cout << "Stack 2 Overflow!" << endl;
            return;
        }
        arr[--top2] = data;
    }

    void pop1() {
        if (top1 == -1) {
            cout << "Stack 1 Underflow!" << endl;
            return;
        }
        arr[top1--] = 0;
    }

    void pop2() {
        if (top2 == size) {
            cout << "Stack 2 Underflow!" << endl;
            return;
        }
        arr[top2++] = 0;
    }

    int getTop1() {
        if (top1 != -1)
            return arr[top1];
        else
            return -1; // or throw an exception
    }

    int getTop2() {
        if (top2 != size)
            return arr[top2];
        else
            return -1; // or throw an exception
    }
};

bool checkRedundantBracket(string s) {
    stack<char> st;
    int n = s.size();
    
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        
        if (ch == ')') {
            bool operatorFound = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
                st.pop();
            }
            st.pop(); // pop the '('
            
            if (!operatorFound) {
                return true; // redundant brackets found
            }
        } else {
            st.push(ch);
        }
    }
    
    return false; // no redundant brackets found
}

int main() {
    // Test the Stack class
    Stack st(5);
    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push2(4);
    
    cout << "Top of Stack 1: " << st.getTop1() << endl;
    cout << "Top of Stack 2: " << st.getTop2() << endl;
    
    st.pop1();
    st.pop2();
    
    cout << "After popping, Top of Stack 1: " << st.getTop1() << endl;
    cout << "After popping, Top of Stack 2: " << st.getTop2() << endl;
    
    // Test checkRedundantBracket function
    string str = "((a+b)*(a+b))";
    if (checkRedundantBracket(str)) {
        cout << "Redundant brackets found!" << endl;
    } else {
        cout << "No redundant brackets found." << endl;
    }
    
    return 0;
}
