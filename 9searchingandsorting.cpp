#include <iostream>
#include <vector>
using namespace std;

// Function to find the pivot index in a rotated sorted array
int findPivotIndex(vector<int>& arr) {
    int n = arr.size();
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e) { 
        // Corner case: Single element
        if (s == e) {
            return s;
        }

        if (mid + 1 < n && arr[mid] > arr[mid + 1])
            return mid;
        else if (mid - 1 >= 0 && arr[mid] < arr[mid - 1])
            return mid - 1;
        else if (arr[s] > arr[mid])
            e = mid - 1;
        else
            s = mid + 1;

        mid = s + (e - s) / 2;
    }
    return -1;
}

// Function to perform binary search
int binarySearch(vector<int>& arr, int s, int e, int target) {
    int mid = s + (e - s) / 2;
    while (s <= e) {
        if (arr[mid] == target) {
            return mid;
        }
        if (target > arr[mid]) {
            s = mid + 1;
        } else {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return -1;
}

// Function to find the square root of a number
int mySqrt(int x) {
    long long int s = 0;
    long long int e = x;
    long long int mid;
    int ans = -1;

    while (s <= e) {
        mid = s + (e - s) / 2;
        if (mid * mid == x) {
            return mid;
        } else if (mid * mid < x) {
            ans = mid; // Store potential answer
            s = mid + 1; // Go to the right half
        } else {
            e = mid - 1; // Go to the left half
        }
    }
    return ans;
}

// Function to search for a target in a 2D matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();
    int n = row * col;

    int s = 0;
    int e = n - 1;
    int mid;

    while (s <= e) {
        mid = s + (e - s) / 2;
        int rowIndex = mid / col;
        int colIndex = mid % col;
        int currNumber = matrix[rowIndex][colIndex];

        if (currNumber == target)
            return true;
        else if (currNumber < target)
            s = mid + 1; // Move to the right
        else
            e = mid - 1; // Move to the left
    }
    return false;
}

int main() {
    // Test for findPivotIndex function
    vector<int> rotatedSortedArray = {4, 5, 6, 7, 0, 1, 2};
    int pivotIndex = findPivotIndex(rotatedSortedArray);
    cout << "Pivot Index is: " << pivotIndex << endl;

    // Test for binarySearch function
    vector<int> sortedArray = {2, 4, 6, 8, 10};
    int target = 6;
    int index = binarySearch(sortedArray, 0, sortedArray.size() - 1, target);
    if (index != -1) {
        cout << "Target " << target << " found at index " << index << endl;
    } else {
        cout << "Target " << target << " not found in the array" << endl;
    }

    // Test for mySqrt function
    int number = 16;
    int sqrtValue = mySqrt(number);
    cout << "Square root of " << number << " is: " << sqrtValue << endl;

    // Test for searchMatrix function
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int targetMatrix = 3;
    bool found = searchMatrix(matrix, targetMatrix);
    if (found) {
        cout << "Target " << targetMatrix << " found in the matrix" << endl;
    } else {
        cout << "Target " << targetMatrix << " not found in the matrix" << endl;
    }

    return 0;
}
