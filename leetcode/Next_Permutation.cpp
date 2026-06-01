// ────────────────────────────────────────────────────────────
// Problem : Next Permutation
// Platform: LeetCode
// URL     : https://leetcode.com/problems/next-permutation/
// Language: cpp
// Date    : 6/1/2026, 5:19:48 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(nlogn)
// Space Complexity: O(1)
// Notes           : Arrays
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int breakPt=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                breakPt=i;
                break;
            }
        }
        if(breakPt==-1){
            sort(nums.begin(),nums.end());
        }
        else{
            for(int i=n-1;i>breakPt;i--){
                if(nums[i]>nums[breakPt]){
                    swap(nums[i],nums[breakPt]);
                    break;
                }
            }
            sort(nums.begin()+breakPt+1,nums.end());
        }
    }
};