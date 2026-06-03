// ────────────────────────────────────────────────────────────
// Problem : Merge Intervals
// Platform: LeetCode
// URL     : https://leetcode.com/problems/merge-intervals/submissions/2020943093/
// Language: cpp
// Date    : 6/3/2026, 12:21:46 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n^2)
// Notes           : Arrays 2
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int n=intervals.size();
        int a=intervals[0][0],b=intervals[0][1];
        ans.push_back({a,b});
        for(int i=1;i<n;i++){
            if(b>=intervals[i][0]){
                ans.pop_back();
                b=max(b,intervals[i][1]);
                ans.push_back({a,b});
            }
            else{
                a=intervals[i][0];
                b=intervals[i][1];
                ans.push_back({a,b});
            }
        }
        return ans;
    }
};