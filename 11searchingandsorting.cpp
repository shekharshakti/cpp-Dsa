#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v) {
  for (int i = 0; i < v.size(); ++i) {
    cout << v[i] << " ";
  }
  cout << endl;
}

void bubbleSort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; ++i) {
    for (int j = 0; j < n - i - 1; ++j) {
      if (v[j] > v[j + 1]) {
        swap(v[j], v[j + 1]);
      }
    }
  }
}

void selectionSort(vector<int> &v) {
  int n = v.size();
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i; // ith element is assumed to be the smallest
    for (int j = i + 1; j < n; j++) {
      if (v[j] < v[minIndex]) {
        minIndex = j;
      }
    }

    // Swap the smallest element with the ith element
    swap(v[i], v[minIndex]);
  }
}

void insertionSort(vector<int> &v) {
  int n = v.size();
  for (int i = 1; i < n; ++i) {
    int key = v[i];
    int j = i - 1;

    // Move elements of v[0..i-1] that are greater than key to one position ahead of their current position
    while (j >= 0 && v[j] > key) {
      v[j + 1] = v[j];
      j--;
    }
    v[j + 1] = key; // Insertion of key
  }
}

int main() {
  vector<int> v = {44, 33, 55, 22, 11};
  
  // Uncomment one of the sorting methods below to see its effect
  // bubbleSort(v);
  // selectionSort(v);
  insertionSort(v);
  
  cout << "Sorted array: ";
  print(v);

  return 0;
}
