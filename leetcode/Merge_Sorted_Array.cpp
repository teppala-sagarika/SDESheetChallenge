// ────────────────────────────────────────────────────────────
// Problem : Merge Sorted Array
// Platform: LeetCode
// URL     : https://leetcode.com/problems/merge-sorted-array/
// Language: cpp
// Date    : 6/3/2026, 12:57:12 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(m+n)
// Space Complexity: O(1)
// Notes           : Arrays 2 (2 pointer approach)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=m-1;
        int j=n-1;
        int idx=m+n-1;
        while(i>=0 && j>=0){
            if(nums1[i]>=nums2[j]){
                nums1[idx]=nums1[i];
                i--;
            }
            else{
                nums1[idx]=nums2[j];
                j--;
            }
            idx--;
        }
        while(i>=0){
            nums1[idx]=nums1[i];
            i--;
            idx--;
        }
        while(j>=0){
            nums1[idx]=nums2[j];
            j--;
            idx--;
        }
    }
};