// ────────────────────────────────────────────────────────────
// Problem : Word Break
// Platform: LeetCode
// URL     : https://leetcode.com/problems/word-break/submissions/2038891835/
// Language: cpp
// Date    : 6/19/2026, 9:02:01 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n^3)
// Space Complexity: O(n)
// Notes           : tabulation
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(n+1,0);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
        for(int l=1;i+l<=n ;l++){
            string sub=s.substr(i,l);
            if(dict.find(sub)!=dict.end() && dp[i+l]){
                dp[i]=1;
                break;
            }
        }
        }
        return dp[0];
    }
};