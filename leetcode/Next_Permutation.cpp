// ────────────────────────────────────────────────────────────
// Problem : Next Permutation
// Platform: LeetCode
// URL     : https://leetcode.com/problems/next-permutation/submissions/2018833885/
// Language: cpp
// Date    : 6/1/2026, 12:40:14 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : arrays ( builtin func )
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(),nums.end());
    }
};