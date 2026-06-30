// ────────────────────────────────────────────────────────────
// Problem : Longest Common Prefix
// Platform: LeetCode
// URL     : https://leetcode.com/problems/longest-common-prefix/submissions/2051442412/
// Language: cpp
// Date    : 6/30/2026, 10:03:10 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n log n + m)
// Space Complexity: O(1)
// Notes           : m = smallest string
// ────────────────────────────────────────────────────────────

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int l=strs.size();
        int n=strs[0].length();
        int i=0;
        string ans="";
        while(i<n && strs[0][i]==strs[l-1][i]){
            ans+=strs[0][i];
            i++;
        }
        return ans;
    }
};