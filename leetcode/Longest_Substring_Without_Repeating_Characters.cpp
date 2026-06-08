// ────────────────────────────────────────────────────────────
// Problem : Longest Substring Without Repeating Characters
// Platform: LeetCode
// URL     : https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/2026620140/
// Language: cpp
// Date    : 6/8/2026, 10:29:41 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : 2 pointer and sliding window could be possible whenever u see abt substring in questions
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int l=0;
        int r=0;
        int len=0;
        int mp[256];
        memset(mp, -1, sizeof(mp));
        while(r<n){
                if(mp[s[r]]!=-1 && mp[s[r]]>=l){
                    l=mp[s[r]]+1;
                }
                mp[s[r]]=r;
                len=max(len,r-l+1);
                r++;
        }
        return len;
    }
};