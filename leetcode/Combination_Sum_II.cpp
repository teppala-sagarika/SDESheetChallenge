// ────────────────────────────────────────────────────────────
// Problem : Combination Sum II
// Platform: LeetCode
// URL     : https://leetcode.com/problems/combination-sum-ii/submissions/2036551185/
// Language: cpp
// Date    : 6/17/2026, 9:12:57 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(2^n)
// Space Complexity: O(n)
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
        for(int j=i;j<n;j++){
            if(j>i && candidates[j]==candidates[j-1]) continue;
                if(candidates[j]>target) break;
                temp.push_back(candidates[j]);
                solve(j+1,n,candidates,target-candidates[j],temp);
                temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int> temp;
        solve(0,n,candidates,target,temp);
        return ans;
    }
};