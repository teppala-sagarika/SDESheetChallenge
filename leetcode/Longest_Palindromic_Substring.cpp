// ────────────────────────────────────────────────────────────
// Problem : Longest Palindromic Substring
// Platform: LeetCode
// URL     : https://leetcode.com/problems/longest-palindromic-substring/submissions/2050191859/
// Language: cpp
// Date    : 6/29/2026, 8:31:32 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n^2)
// Space Complexity: O(n^2)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool isPal(int l,int r,string &s,vector<vector<int>> &dp){
        if(l>=r){
            return true;
        }
        if(dp[l][r]!=-1) return dp[l][r];
        if(s[l]==s[r]){
           return dp[l][r]=isPal(l+1,r-1,s,dp);
        }
        return dp[l][r]=false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int len = n; len >= 1; len--){
            for(int start = 0; start <= n-len; start++){
                int end = start + len - 1;
                if(isPal(start, end, s,dp)){
                    return s.substr(start, len);
                }
            }
        }
        return "";
    }
};