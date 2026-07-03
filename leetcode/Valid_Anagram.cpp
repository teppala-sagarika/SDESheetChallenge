// ────────────────────────────────────────────────────────────
// Problem : Valid Anagram
// Platform: LeetCode
// URL     : https://leetcode.com/problems/valid-anagram/?__cf_chl_f_tk=4lz16dECB3dxX6UGCELVzb7jcXTITf8wEnDNxVG1Ad4-1783091360-1.0.1.1-xZlbxWHG7sxDrLrSMT3Gks_qnB.KTwFjrK5WKInaDdY
// Language: cpp
// Date    : 7/3/2026, 9:00:20 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};
//T.C = O(n log n)
//S.C = O(log n) //Maximum stack depth = log n