#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// Definition of ListNode for subsequences
void findSubsequences(string str, string output, int index, vector<string>& ans) {
    //base case
    if(index >= str.length()) {
        ans.push_back(output);
        return;
    }

    char ch = str[index];

    //include
    output.push_back(ch);
    findSubsequences(str, output, index+1, ans);

    //exclude
    output.pop_back();
    findSubsequences(str, output, index+1, ans);
}

// Function to create subsequences and print them
void printSubsequences(string str) {
    string output = "";
    int index = 0;
    vector<string> ans;
    findSubsequences(str, output, index, ans);

    cout << "Printing the subsequences:" << endl;
    for(string s: ans) {
        cout << "-> " << s << endl;
    }
}

// Coin change problem class
class CoinChangeSolution {
public:
    int solve(vector<int>& coins, int amount) {
        // base case
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return INT_MAX;
        }

        int mini = INT_MAX;
        
        for(int i = 0; i < coins.size(); i++) {
            int coin = coins[i];

            // current coin ko tabhi use krenge jab uski value <= amount hogi 
            if(coin <= amount) {
                int recAns = solve(coins, amount - coin);
                if(recAns != INT_MAX) {
                    int ans = 1 + recAns;
                    mini = min(mini, ans);
                }    
            }
        }
        return mini;
    }

    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins, amount);

        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};

// Max sum of non-adjacent elements problem class
class RobSolution {
public:
    int solve(vector<int>& nums, int size, int index) {
        // base case
        if(index >= size) {
            return 0;
        }

        // take current index element
        int option1 = nums[index] + solve(nums, size, index + 2);

        // do not take current index element
        int option2 = 0 + solve(nums, size, index + 1);

        int finalAns = max(option1, option2);
        return finalAns;
    }

    int rob(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        int ans = solve(nums, size, index);
        return ans;
    }
};

int main() {
    // Example usage of subsequences function
    string str = "abc";
    printSubsequences(str);
    cout << endl;

    // Example usage of coin change problem
    CoinChangeSolution coinChangeSol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int coinChangeResult = coinChangeSol.coinChange(coins, amount);
    cout << "Minimum coins required for amount " << amount << ": " << coinChangeResult << endl;

    // Example usage of max sum of non-adjacent elements problem
    RobSolution robSol;
    vector<int> nums = {2, 7, 9, 3, 1};
    int maxSum = robSol.rob(nums);
    cout << "Maximum sum of non-adjacent elements: " << maxSum << endl;

    return 0;
}
