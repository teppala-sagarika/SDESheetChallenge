// ────────────────────────────────────────────────────────────
// Problem : Find the Index of the First Occurrence in a String
// Platform: LeetCode
// URL     : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
// Language: cpp
// Date    : 7/3/2026, 8:31:24 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n+m)
// Space Complexity: O(m)
// Notes           : LPS = longest prefix which is also suffix
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> buildLPS(string pattern) {
        int m = pattern.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;
        while (i < m) {
            if (pattern[i] == pattern[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    i++;
                }
            }
        }
        return lps;
    }

    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        vector<int> lps = buildLPS(needle);
        int i = 0;
        int j = 0;
        while (i < haystack.size()) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == needle.size()) {
                return i - j;
            }
            else if (i < haystack.size() && haystack[i] != needle[j]) {
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
};