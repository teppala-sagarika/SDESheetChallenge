// ────────────────────────────────────────────────────────────
// Problem : Palindrome Partitioning
// Platform: LeetCode
// URL     : https://leetcode.com/problems/palindrome-partitioning/submissions/2036606844/
// Language: cpp
// Date    : 6/17/2026, 10:00:01 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N * 2^N)
// Space Complexity: O(N)
// Notes           : recursion
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string &s, int start, int end){
        while(start <= end){
            if(s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void solve(int i, string &s, vector<string>& temp){
        if(i == s.size()){
            ans.push_back(temp);
            return;
        }
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                temp.push_back(s.substr(i, j-i+1));
                solve(j+1, s, temp);
                // backtrack
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, s, temp);
        return ans;
    }
};