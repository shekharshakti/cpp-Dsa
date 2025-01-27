#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        int index = 0;

        while(index < s.length()) {
            if(ans.length() > 0 && ans.back() == s[index]) {
                ans.pop_back();
            }
            else {
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }

    string removeOccurrences(string s, string part) {
        while(s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }

    bool checkPalindrome(string s, int i, int j) {
        while( i<= j) {
            if(s[i] != s[j]) {
                return false;
            }
            else {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while( i <= j) {
            if(s[i] == s[j]) {
                i++;
                j--;
            }
            else {
                bool ans1 = checkPalindrome(s, i+1, j);
                bool ans2 = checkPalindrome(s, i, j-1);
                return ans1 || ans2;
            }
        }
        return true;
    }

    int expand(string s, int i, int j) {
        int count = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int totalCount = 0;
        for(int i = 0; i < s.length(); i++) {
            int j = i;
            int oddKaAns = expand(s, i, j);  
            j = i+1;
            int evenKaAns = expand(s, i, j);
            totalCount = totalCount + oddKaAns + evenKaAns;
        }
        return totalCount;
    }
};

int main() {
    Solution sol;

    // Example for removeDuplicates
    string s1 = "abbaca";
    cout << "Original string: " << s1 << endl;
    string result1 = sol.removeDuplicates(s1);
    cout << "String after removing adjacent duplicates: " << result1 << endl;

    // Example for removeOccurrences
    string s2 = "daabcbaabcbc";
    string part = "abc";
    cout << "Original string: " << s2 << endl;
    string result2 = sol.removeOccurrences(s2, part);
    cout << "String after removing all occurrences of \"" << part << "\": " << result2 << endl;

    // Example for validPalindrome
    string s3 = "abca";
    cout << "String: " << s3 << endl;
    bool isPalindrome = sol.validPalindrome(s3);
    if (isPalindrome) {
        cout << "String \"" << s3 << "\" can be made a palindrome with at most 1 removal." << endl;
    } else {
        cout << "String \"" << s3 << "\" cannot be made a palindrome with at most 1 removal." << endl;
    }

    // Example for countSubstrings
    string s4 = "abc";
    cout << "String: " << s4 << endl;
    int count = sol.countSubstrings(s4);
    cout << "Number of palindromic substrings: " << count << endl;

    return 0;
}
