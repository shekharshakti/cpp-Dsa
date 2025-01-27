#include <iostream>
using namespace std;

// Function to find the quotient of dividend divided by divisor
int getQuotient(int divisor, int dividend) {
  int s = 0;
  int e = dividend;
  int ans = -1;
  int mid = s + (e - s) / 2;

  while (s <= e) {
    if (mid * divisor == dividend) {
      return mid;
    }
    if (mid * divisor < dividend) {
      ans = mid; // Store potential answer
      s = mid + 1; // Move to the right half
    } else {
      e = mid - 1; // Move to the left half
    }
    mid = s + (e - s) / 2;
  }
  return ans;
}

// Function to search for target in a nearly sorted array
int searchNearlySorted(int arr[], int n, int target) {
  int s = 0;
  int e = n - 1;
  int mid = s + (e - s) / 2;

  while (s <= e) {
    if (mid - 1 >= 0 && arr[mid - 1] == target) {
      return mid - 1;
    }
    if (arr[mid] == target)
      return mid;

    if (mid + 1 < n && arr[mid + 1] == target)
      return mid + 1;

    if (target > arr[mid]) {
      s = mid + 2; // Move to the right
    } else {
      e = mid - 2; // Move to the left
    }
    mid = s + (e - s) / 2;
  }
  return -1;
}

// Function to find the index of the element occurring odd number of times in an array
int findOddOccuringElement(int arr[], int n) {
  int s = 0;
  int e = n - 1;
  int mid = s + (e - s) / 2;

  while (s <= e) {
    // Single element case
    if (s == e) {
      return s;
    }

    // Check if mid is odd or even
    if (mid & 1) { // Odd mid index
      if (mid - 1 >= 0 && arr[mid - 1] == arr[mid]) {
        s = mid + 1; // Move to the right
      } else {
        e = mid - 1; // Move to the left
      }
    } else { // Even mid index
      if (mid + 1 < n && arr[mid] == arr[mid + 1]) {
        s = mid + 2; // Move to the right
      } else {
        e = mid; // Move to the left or current is the answer
      }
    }
    mid = s + (e - s) / 2;
  }
  return -1;
}

int main() {
  // Test getQuotient function
  int divisor = 7;
  int dividend = 29;
  int ans = getQuotient(abs(divisor), abs(dividend));

  // Determine the sign of the quotient
  if ((divisor > 0 && dividend < 0) || (divisor < 0 && dividend > 0)) {
    ans = 0 - ans;
  }
  cout << "Quotient of " << dividend << " divided by " << divisor << " is: " << ans << endl;

  // Test searchNearlySorted function
  int arr[] = {20, 10, 30, 50, 40, 70, 60};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target = 20;
  int targetIndex = searchNearlySorted(arr, n, target);

  if (targetIndex == -1) {
    cout << "Element " << target << " Not found in the nearly sorted array" << endl;
  } else {
    cout << "Element " << target << " Found at Index: " << targetIndex << endl;
  }

  // Test findOddOccuringElement function
  int arrOdd[] = {10, 10, 10, 20, 20, 30, 30};
  int nOdd = sizeof(arrOdd) / sizeof(arrOdd[0]);
  int ansIndex = findOddOccuringElement(arrOdd, nOdd);

  if (ansIndex == -1) {
    cout << "No element with odd occurrences found in the array" << endl;
  } else {
    cout << "Element occurring odd number of times is: " << arrOdd[ansIndex] << endl;
  }

  return 0;
}
