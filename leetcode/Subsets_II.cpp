// ────────────────────────────────────────────────────────────
// Problem : Subsets II
// Platform: LeetCode
// URL     : https://leetcode.com/problems/subsets-ii/submissions/2035300628/
// Language: cpp
// Date    : 6/16/2026, 8:30:55 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n*2^n)
// Space Complexity: O(n)
// Notes           : recursion
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i, vector<int>& nums, vector<int>& temp){
        ans.push_back(temp);
        for(int j=i; j<nums.size(); j++){
            if(j>i && nums[j]==nums[j-1])
                continue;
            temp.push_back(nums[j]);
            solve(j+1, nums, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }
};