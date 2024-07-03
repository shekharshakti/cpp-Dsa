#include <iostream>
#include <vector>
using namespace std;

// Binary Search function
int binarySearch(int arr[], int n, int target) {
    int start = 0;
    int end = n - 1;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (arr[mid] == target) {
            return mid; // found the target
        } else if (target > arr[mid]) {
            start = mid + 1; // go to the right half
        } else {
            end = mid - 1; // go to the left half
        }
    }
    return -1; // element not found
}

// Function to find the missing element in a sorted array
int findMissingElement(int arr[], int n) {
    int s = 0;
    int e = n - 1;
    while (s <= e) {
        int mid = s + (e - s) / 2;
        if (arr[mid] == mid + 1) {
            s = mid + 1; // go to the right half
        } else {
            e = mid - 1; // go to the left half
        }
    }
    return s + 1; // the missing element
}

int main() {
    // Example for binary search
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 9;

    int index = binarySearch(arr, n, target);
    if (index != -1) {
        cout << "Element " << target << " found at index " << index << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    // Example for finding missing element
    int arr2[] = {1, 2, 3, 4, 5, 7, 8};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    int missingElement = findMissingElement(arr2, n2);
    cout << "Missing element in the array is: " << missingElement << endl;

    return 0;
}
