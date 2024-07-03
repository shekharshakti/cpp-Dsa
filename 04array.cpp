#include <iostream>
#include <vector>
#include <climits> // for INT_MIN
using namespace std;

// Function to segregate negative and positive numbers
void shiftNegativeOneSide(int arr[], int n) {
    int j = 0;
    for(int index=0; index<n; index++) {
        if(arr[index] < 0) {
            swap(arr[index], arr[j]);
            j++;
        }
    }
}

// Function to sort colors (0s, 1s, 2s)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int left = 0;
        int right = n-1;

        while(index <= right) {
            if(nums[index] == 0) {
                swap(nums[index], nums[left]);
                left++;
                index++;
            }
            else if(nums[index] == 2) {
                swap(nums[index], nums[right]);
                right--;
            }
            else {
                index++;
            }
        }
    }
};

// Function to rotate an array
class SolutionRotate {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n);

        for(int index=0; index<n; index++) {
            int newIndex = (index + k ) % n;
            ans[newIndex] = nums[index];
        }

        nums = ans;
    }
};

// Function to find missing number in a sequence
class SolutionMissingNumber {
public:
    int missingNumber(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for(int index=0;index<n; index++) {
            sum = sum + nums[index];
        }

        int totalSum = ((n)*(n+1))/2;
        int ans = totalSum - sum;
        return ans;
    }
};

// Function to rearrange array (positive at even indices, negative at odd indices)
class SolutionRearrangeArray {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        int evenIndex = 0;
        int oddIndex = 1;
        vector<int> ans(n);

       while(index < n ) {
           if(nums[index] > 0) {
                ans[evenIndex] = nums[index];
                evenIndex += 2;
           }
           index++;
       }

       index = 0;
       while(index < n ) {
           if(nums[index] < 0) {
                ans[oddIndex] = nums[index];
                oddIndex += 2;
           }
           index++;
       }
       return ans;
    }
};

// Function to find row with maximum number of 1s in a binary matrix
class SolutionMaxOnesRow {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        vector<int> ans;
        int n = mat.size();
        int oneCount = INT_MIN;
        int rowNo ;

        for(int i=0; i<n; i++) {
            int count = 0;
            for(int j=0; j<mat[i].size(); j++) {
                if(mat[i][j] == 1) {
                    count++;
                }
            }
            if(count > oneCount) {
                oneCount = count;
                rowNo = i;
            }
        }

        ans.push_back(rowNo);
        ans.push_back(oneCount);
        return ans;
    }
};

// Function to rotate a square matrix (image) 90 degrees clockwise
class SolutionRotateImage {
public:
    void reverseVector(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n-1;

        while(start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Transpose matrix
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Reverse rows
        for(int i=0; i<n; i++) {
            reverseVector(matrix[i]);
        }
    }
};

// Main function to test all the functionalities
int main() {
    // Example for segregate negative and positive numbers
    int arr[] = {1, -7, 12, -10, 11, 40, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    shiftNegativeOneSide(arr, n);
    cout << "Segregated Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Example for sorting colors
    vector<int> colors = {2, 0, 1, 2, 1, 0};
    Solution sortColorsSolution;
    sortColorsSolution.sortColors(colors);
    cout << "Sorted Colors: ";
    for(int color : colors) {
        cout << color << " ";
    }
    cout << endl;

    // Example for rotating an array
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    SolutionRotate rotateSolution;
    rotateSolution.rotate(nums, 3);
    cout << "Rotated Array: ";
    for(int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    // Example for finding missing number
    vector<int> sequence = {3, 0, 1};
    SolutionMissingNumber missingNumberSolution;
    int missing = missingNumberSolution.missingNumber(sequence);
    cout << "Missing Number: " << missing << endl;

    // Example for rearranging array
    vector<int> rearrangeArray = {1, -3, 5, 2, -8, 7};
    SolutionRearrangeArray rearrangeSolution;
    vector<int> rearranged = rearrangeSolution.rearrangeArray(rearrangeArray);
    cout << "Rearranged Array: ";
    for(int num : rearranged) {
        cout << num << " ";
    }
    cout << endl;

    // Example for finding row with maximum number of 1s
    vector<vector<int>> matrix = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    SolutionMaxOnesRow maxOnesSolution;
    vector<int> result = maxOnesSolution.rowAndMaximumOnes(matrix);
    cout << "Row with maximum 1s: " << result[0] << ", Count: " << result[1] << endl;

    // Example for rotating an image (2D matrix)
    vector<vector<int>> image = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    SolutionRotateImage rotateImageSolution;
    rotateImageSolution.rotate(image);
    cout << "Rotated Image:" << endl;
    for(auto& row : image) {
        for(int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}
