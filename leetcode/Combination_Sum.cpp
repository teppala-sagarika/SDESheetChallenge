// ────────────────────────────────────────────────────────────
// Problem : Combination Sum
// Platform: LeetCode
// URL     : https://leetcode.com/problems/combination-sum/submissions/2036454302/
// Language: cpp
// Date    : 6/17/2026, 7:39:06 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(2^n)
// Space Complexity: O(target/min(candidates))
// Notes           : recursion
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,int n,vector<int>& candidates, int target,vector<int>& temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=n) return;
        //no take
        solve(i+1,n,candidates,target,temp);
        //take
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            solve(i,n,candidates,target-candidates[i],temp);
            //backtrack
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,n,candidates,target,temp);
        return ans;
    }
};