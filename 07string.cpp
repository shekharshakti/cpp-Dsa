#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void createUpdateMapping(string& str) {
        char start = 'a';
        char mapping[300] = {0};

        for(auto ch: str) {
            if(mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            str[i] = mapping[ch];
        }
    }

    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        createUpdateMapping(pattern);

        for(string s: words) {
            string tempString = s;
            createUpdateMapping(tempString);
            if(tempString == pattern) {
                ans.push_back(s);
            }
        }
        return ans;
    }

    string decodeMessage(string key, string message) {
        char start = 'a';
        char mapping[1000] = {0};

        for(auto ch: key) {
            if(ch != ' ' && mapping[ch] == 0) {
                mapping[ch] = start;
                start++;
            }
        }

        string ans;

        for(auto ch: message) {
            if(ch == ' ') {
                ans.push_back(' ');
            }
            else {
                char decodedChar = mapping[ch];
                ans.push_back(decodedChar);
            }
        }
        return ans;
    }

    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int pickP = 0, pickM = 0, pickG = 0;
        int travelP = 0, travelG = 0, travelM = 0;
        int lastP = 0, lastG = 0, lastM = 0;

        for(int i=0; i<garbage.size(); i++) {
            string curr = garbage[i];
            
            for(int j=0; j<curr.length(); j++) {
                char ch = curr[j];

                if(ch =='P') {
                    pickP++;
                    lastP = i;
                }
                else if(ch =='G') {
                    pickG++;
                    lastG = i;
                }
                else if(ch == 'M' ) {
                    pickM++;
                    lastM = i;
                }
            }
        }

        for(int i=0; i<lastP; i++) {
            travelP += travel[i];
        }

        for(int i=0; i<lastG; i++) {
            travelG += travel[i];
        }

        for(int i=0; i<lastM; i++) {
            travelM += travel[i];
        }

        int ans = (pickP + travelP) + (pickG + travelG) + (pickM + travelM);
        return ans;
    }

    static string str;
    static bool compare(char char1, char char2) {
        return (str.find(char1) < str.find(char2));
    }

    string customSortString(string order, string s) {
        str = order;
        sort(s.begin(), s.end(), compare);
        return s;
    }
};

string Solution::str;

int main() {
    Solution sol;

    // Example for findAndReplacePattern
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> resultPattern = sol.findAndReplacePattern(words, pattern);
    cout << "Pattern Matching Results:" << endl;
    for (const auto& word : resultPattern) {
        cout << word << " ";
    }
    cout << endl;

    // Example for decodeMessage
    string key = "abcdefghijklmnopqrstuvwxyz";
    string message = "12 34";
    string decodedMessage = sol.decodeMessage(key, message);
    cout << "Decoded Message: " << decodedMessage << endl;

    // Example for garbageCollection
    vector<string> garbage = {"MGMP", "GGPMM", "PM"};
    vector<int> travel = {1, 2, 1};
    int minTime = sol.garbageCollection(garbage, travel);
    cout << "Minimum Time to Collect Garbage: " << minTime << endl;

    // Example for customSortString
    string order = "cba";
    string str = "abcd";
    string sortedStr = sol.customSortString(order, str);
    cout << "Custom Sorted String: " << sortedStr << endl;

    return 0;
}
