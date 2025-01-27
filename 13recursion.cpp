#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void printArray(int *arr, int size, int index) {
    //base case
    if(index >= size) {
        return ;
    }
    
    //recursive call
    printArray(arr, size, index+1);
    
    //processing
    cout << arr[index] << " ";
}

bool searchArray(int arr[], int size, int target, int index) {
    //base case
    if(index >= size) {
        return false;
    }
    if(arr[index] == target) {
        return true;
    }
    
    //recursive call
    bool aageKaAns = searchArray(arr, size, target, index+1);
    return aageKaAns;
}

void findMin(int arr[], int size, int index, int &mini) {
    //base case
    if(index >= size) {
        return;
    }
    
    //processing
    mini = min(mini, arr[index]);
    
    //Recursive call
    findMin(arr, size, index+1 , mini);
}

//solve() -> store even numbers in array into vector
void solve(int arr[], int size, int index, vector<int> &ans) {
    //base case
    if(index >= size) {
        return;
    }
    
    //processing
    if(arr[index] % 2 == 0) {
        //even
        ans.push_back(arr[index]);
    }
    
    //Recursive call
    solve(arr, size, index+1, ans);
}

void printDigits(int num, vector<int>& ans) {
    //base case
    if(num == 0) {
        return;
    }
    
    //processing
    int digit = num % 10;
    
    //Recursive call
    printDigits(num / 10, ans);
    
    //processing
    ans.push_back(digit);
}

int main() {
    int num = 4217;
    vector<int> ans;
    printDigits(num, ans);
    
    cout << "Digits of " << num << " are: ";
    for(int digit : ans) {
        cout << digit << " ";
    }
    cout << endl;

    // Uncomment below to test other functions
    
    int arr[] = {11, 20, 31, 40, 51};
    int size = 5;
    int index = 0;
    vector<int> ansVector;
    
    solve(arr, size, index, ansVector);
    
    //printing vector
    cout << "Even numbers in array: ";
    for(int num : ansVector) {
        cout << num << " ";
    }
    cout << endl;
    
    int mini = INT_MAX;
    findMin(arr, size, index, mini);
    cout << "Minimum number in array: " << mini << endl;
    
    int target = 50;
    cout <<"Target found or not: "<< searchArray(arr, size, target, index) << endl;
    
    cout << "Array elements: ";
    printArray(arr, size, index);
    cout << endl;
    
    
    return 0;
}
