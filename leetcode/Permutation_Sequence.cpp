// ────────────────────────────────────────────────────────────
// Problem : Permutation Sequence
// Platform: LeetCode
// URL     : https://leetcode.com/problems/permutation-sequence/submissions/2036623117/
// Language: cpp
// Date    : 6/17/2026, 10:13:33 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(N^2)
// Space Complexity: O(N)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    string solve(vector<int>& nums, int k){
        int n = nums.size();
        // base case
        if(n == 1)
            return to_string(nums[0]);
        int fact = 1;
        for(int i=1; i<n; i++)
            fact *= i;
        // find index
        int index = k / fact;
        // take element
        int val = nums[index];
        nums.erase(nums.begin()+index);
        // remaining k
        k = k % fact;
        return to_string(val) + solve(nums, k);
    }

    string getPermutation(int n, int k) {
        vector<int> nums;
        for(int i=1; i<=n; i++)
            nums.push_back(i);
        return solve(nums, k-1);
    }
};