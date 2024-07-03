#include<iostream>
using namespace std;

void sortZeroOne(int arr[], int n) {
    int ZeroCount = 0;
    int OneCount = 0;

    // Counting number of 0s and 1s in the array
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            ZeroCount++;
        } else if (arr[i] == 1) {
            OneCount++;
        }
    }

    // Placing 0s in the beginning of the array
    for (int i = 0; i < ZeroCount; i++) {
        arr[i] = 0;
    }

    // Placing 1s after 0s in the array
    for (int i = ZeroCount; i < ZeroCount + OneCount; i++) {
        arr[i] = 1;
    }
}

int getUnique(int arr[], int n){
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

void shiftArray(int arr[], int n){
    int temp = arr[n-1];
    for(int i = n-1; i >= 1; i--){
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main() {
    int arr[] = {2, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0};
    int n = 15;

    sortZeroOne(arr, n);

    // Printing the sorted array
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int uniqueno = getUnique(arr, n);
    cout << "Unique number is: " << uniqueno << endl;

    shiftArray(arr, n);

    // Printing the shifted array
    cout << "Shifted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
