#include <iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st, int &element) {
  //base case
  if(st.empty()) {
    st.push(element);
    return;
  }

  //1 case main solve karunga
  int temp = st.top();
  st.pop();

  //baaaki recursion
  insertAtBottom(st, element);

  //backTrack
  st.push(temp);
}

void reverseStack(stack<int> &st) {
  //base case
  if(st.empty()) {
    return;
  }
  //1 case main solve krega
  int temp = st.top();
  st.pop();
  //refcursion
  reverseStack(st);
  //backtrack
  insertAtBottom(st,temp);
}

void insertSorted(stack<int> &st, int element) {
  //base case
  if(st.empty() || element > st.top()) {
    st.push(element);
    return;
  }

  //1 case sambhalna h
  int temp = st.top();
  st.pop();
  //recursion sambhalega
  insertSorted(st,element);
  //backtrack
  st.push(temp);
}

void sortStack(stack<int> &st) {
  //base case
  if(st.empty()) {
    return;
  }

  //1 case
  int temp = st.top();
  st.pop();

  //recursion
  sortStack(st);

  //backtrack
  insertSorted(st, temp);
}
void solve(stack<int> &st, int& pos, int &ans) {
  //base case
  if(pos == 1) {
    //ans =  st.top();
    cout << "Deleting "<< st.top() << endl;
    st.pop();
    return;
  }
  //1 case hum solve krenge
  pos--;
  int temp = st.top();
  st.pop();
  //recursion
  solve(st,pos,ans);
  //backtracjk
  st.push(temp);
}

int getMiddleElement(stack<int> &st) {
  int size = st.size();
  if(st.empty()){
    cout << "Stack is empty, no middle element" << endl;
    return -1;
  }
  else {
    //stack is not empty
    //odd
    int pos = 0;
    if(size & 1) {
      pos = size/2 + 1;
    }
    else {
      //even
      pos = size/2;
    }
    int ans = -1;
    solve(st,pos,ans);
    return ans;
  }
}

int main() {
  stack<int> st;
  st.push(10);
  st.push(20);
  st.push(30);
  st.push(50);
  st.push(60);

  cout << "before size" << st.size() << endl; 
  int mid = getMiddleElement(st);
  cout << "Middle element: " << mid << endl;

  cout << "after size" << st.size() << endl; 
  //   int element = 400;
//   insertAtBottom(st,element);

// without reverse: 
// 30 20 10 

//   reverseStack(st);
// //   with reverse: 
// //   10 20 30
  
//   cout << "with reverse: " << endl;
//insertSorted(st,35);
  sortStack(st);
  while(!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }

  return 0;
  
}