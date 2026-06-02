// ────────────────────────────────────────────────────────────
// Problem : Maximum Subarray
// Platform: LeetCode
// URL     : https://leetcode.com/problems/maximum-subarray/submissions/2019811589/
// Language: cpp
// Date    : 6/2/2026, 11:27:09 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : Kadane's Algorithm
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,sum);
            //Kadane's Algorithm
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};