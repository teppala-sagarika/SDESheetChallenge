// ────────────────────────────────────────────────────────────
// Problem : Compare Version Numbers
// Platform: LeetCode
// URL     : https://leetcode.com/problems/compare-version-numbers/submissions/2055922541/
// Language: cpp
// Date    : 7/4/2026, 8:50:29 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N + M)
// Space Complexity: O(N + M)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string part;
        stringstream ss1(version1), ss2(version2);
        while (getline(ss1, part, '.')) v1.push_back(stoi(part));
        while (getline(ss2, part, '.')) v2.push_back(stoi(part));
        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; ++i) {
            int a = (i < (int)v1.size()) ? v1[i] : 0;
            int b = (i < (int)v2.size()) ? v2[i] : 0;
            if (a < b) return -1;
            if (a > b) return 1;
        }
        return 0;
    }
};