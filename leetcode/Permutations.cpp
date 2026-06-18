// ────────────────────────────────────────────────────────────
// Problem : Permutations
// Platform: LeetCode
// URL     : https://leetcode.com/problems/permutations/submissions/2037777015/
// Language: cpp
// Date    : 6/18/2026, 9:43:51 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n!*n)
// Space Complexity: O(n) + O(n!)
// Notes           : recursion
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void solve(int i,vector<int>& nums,int n,vector<vector<int>>& ans){
        if(i==n){
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<n;j++){
            swap(nums[i],nums[j]);
            solve(i+1,nums,n,ans);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        solve(0,nums,n,ans);
        return ans;
    }
};