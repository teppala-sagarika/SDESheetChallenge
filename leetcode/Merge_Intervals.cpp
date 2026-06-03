// ────────────────────────────────────────────────────────────
// Problem : Merge Intervals
// Platform: LeetCode
// URL     : https://leetcode.com/problems/merge-intervals/submissions/2020906715/
// Language: cpp
// Date    : 6/3/2026, 11:49:08 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n^2)
// Space Complexity: O(n^2)
// Notes           : Arrays 2
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            int a=intervals[i][0],b=intervals[i][1];
            for(int j=i+1;j<n;j++){
                if(b>=intervals[j][0]){
                    b=max(b,intervals[j][1]);
                    i=j;
                }
                else{
                    break;
                }
            }
            ans.push_back({a,b});
        }
        return ans;
    }
};