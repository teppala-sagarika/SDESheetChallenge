// ────────────────────────────────────────────────────────────
// Problem : Remove Duplicates from Sorted Array
// Platform: LeetCode
// URL     : https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/2032650834/
// Language: cpp
// Date    : 6/14/2026, 2:52:25 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : arrays - 2 ptr approach
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int idx=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=nums[idx]){
                nums[idx+1]=nums[i];
                idx++;
            }
        }
        return idx+1;
    }
};