// ────────────────────────────────────────────────────────────
// Problem : Unique Paths
// Platform: LeetCode
// URL     : https://leetcode.com/problems/unique-paths/submissions/2024256801/
// Language: cpp
// Date    : 6/6/2026, 6:53:44 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(min(m,n))
// Space Complexity: O(1)
// Notes           : Combinatorial method
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = m + n - 2;      // total moves
        int r = min(m - 1, n - 1);

        long long ans = 1;

        for (int i = 1; i <= r; i++) {
            ans = ans * (N - r + i) / i;
        }

        return (int)ans;
    }
};