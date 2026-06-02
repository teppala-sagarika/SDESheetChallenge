// ────────────────────────────────────────────────────────────
// Problem : Sort Colors
// Platform: LeetCode
// URL     : https://leetcode.com/problems/sort-colors/submissions/2020071986/
// Language: cpp
// Date    : 6/2/2026, 4:03:42 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : Dutch National Flag Algorithm
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,m=0,h=n-1;
        //Dutch National Flag algorithm 
        while(m<=h){
            if(nums[m]==0){
                swap(nums[m],nums[l]);
                l++;
                m++;
            }
            else if(nums[m]==1){
                m++;
            }
            else{
                swap(nums[m],nums[h]);
                h--;
            }
        }
    }
};