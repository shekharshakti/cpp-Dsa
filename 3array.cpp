#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void printArray(int arr[][4], int row, int col) {
  for(int i = 0; i < row; i++ ) {
    for(int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void colWisePrint(int arr[][4], int row, int col ) {
  for(int i = 0; i < col; i++) {
    for(int j = 0; j < row; j++) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

bool findTarget(int arr[][4], int row, int col, int target) {
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(arr[i][j] == target) {
        return true;
      }
    }
  }
  return false;
}

int findMax(int arr[][4], int row, int col) {
  int maxAns = INT_MIN;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(arr[i][j] > maxAns) {
        maxAns = arr[i][j];
      }
    }
  }
  return maxAns;
}

int findMin(int arr[][4], int row, int col ) {
  int minAns = INT_MAX;
  for(int i = 0; i < row; i++) {
    for(int j = 0; j < col; j++) {
      if(arr[i][j] < minAns) {
        minAns = arr[i][j];
      }
    }
  }
  return minAns;
}

void rowWiseSum(int arr[][4], int row, int col ) {
  for(int i = 0; i < row; i++) {
    int sum = 0;
    for(int j = 0; j < col; j++) {
      sum += arr[i][j];
    }
    cout << "Sum of row " << i << ": " << sum << endl;
  }
}

void transpose(int arr[][4], int row, int col ) {
  for(int i = 0; i < row; i++) {
    for(int j = i; j < col; j++) {
      swap(arr[i][j], arr[j][i]);
    }
  }
}

int main() {
  int arr[3][4] = {
    {1, 2, 3, 4},
    {5, 6, 7, 8},
    {9, 10, 1, 11}
  };
  int row = 3;
  int col = 4;

  cout << "Original Array:" << endl;
  printArray(arr, row, col);

  cout << "\nArray printed column-wise:" << endl;
  colWisePrint(arr, row, col);

  int target = 11;
  cout << "\nFinding target " << target << ": " << (findTarget(arr, row, col, target) ? "Found" : "Not found") << endl;

  cout << "\nMaximum element in array: " << findMax(arr, row, col) << endl;

  cout << "Minimum element in array: " << findMin(arr, row, col) << endl;

  cout << "\nRow-wise sums:" << endl;
  rowWiseSum(arr, row, col);

  cout << "\nArray after transpose:" << endl;
  transpose(arr, row, col);
  printArray(arr, col, row);

// vector<int> arr;
    vector<int> arr1(5);
    vector<int> arr2(5, 101);

    arr1.push_back(4);
    arr1.push_back(8);
    arr1.push_back(12);
    arr1.push_back(11);
    arr1.push_back(4);

    cout << "Size of arr: " << arr1.size() << endl;
    cout << "Is arr empty? " << (arr1.empty() ? "Yes" : "No") << endl;

    cout << endl << "Printing arr:" << endl;
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl << endl;

    // Example 2: 2D Vector (Vector of Vectors) - Jagged Array
    vector< vector<int> > brr;

    vector<int> vec1(10, 0);   // 10 elements initialized to 0
    vector<int> vec2(5, 1);    // 5 elements initialized to 1
    vector<int> vec3(7, 0);    // 7 elements initialized to 0
    vector<int> vec4(8, 1);    // 8 elements initialized to 1
    vector<int> vec5(20, 0);   // 20 elements initialized to 0

    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    // Printing the elements of 2D vector (brr)
    cout << "Printing 2D vector (brr):" << endl;
    for (int i = 0; i < brr.size(); i++) {
        for (int j = 0; j < brr[i].size(); j++) {
            cout << brr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
