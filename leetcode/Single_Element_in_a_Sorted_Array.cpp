// ────────────────────────────────────────────────────────────
// Problem : Single Element in a Sorted Array
// Platform: LeetCode
// URL     : https://leetcode.com/problems/single-element-in-a-sorted-array/
// Language: cpp
// Date    : 6/20/2026, 6:39:56 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(log n)
// Space Complexity: O(1)
// Notes           : Optimal (binary search)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int l=1,h=n-2;
        while(l<=h){
            int m=(l+h)/2;
            int left=nums[m-1];
            int ryt=nums[m+1];
            if(nums[m]!=left && nums[m]!=ryt){
                return nums[m];
            }
            if(m%2==0 && nums[m]==nums[m-1] || m%2!=0 && nums[m]==nums[m+1]){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return -1;
    }
};