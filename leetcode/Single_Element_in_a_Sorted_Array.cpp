// ────────────────────────────────────────────────────────────
// Problem : Single Element in a Sorted Array
// Platform: LeetCode
// URL     : https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/2039782976/
// Language: cpp
// Date    : 6/20/2026, 6:38:53 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : brute force (XOR)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int x=0;
        for(int i=0;i<n;i++){
            x^=nums[i];
        }
        return x;
    }
};