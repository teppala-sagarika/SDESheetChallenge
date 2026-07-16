// ────────────────────────────────────────────────────────────
// Problem : Kth Largest Element in an Array
// Platform: LeetCode
// URL     : https://leetcode.com/problems/kth-largest-element-in-an-array/description/
// Language: cpp
// Date    : 7/16/2026, 12:00:22 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n^2)
// Space Complexity: O(1)
// Notes           : Quick Select - Hoare's Partition
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int quickSelectAlgo(vector<int>& nums,int l,int r){
        int pivot=nums[l];
        int i=l+1;
        int j=r;
        while(i<=j){
            if(nums[i]<pivot && pivot<nums[j]){
                swap(nums[i],nums[j]);
                i++;
                j--;
            }
            if(nums[i]>=pivot){
                i++;
            }
            if(nums[j]<=pivot){
                j--;
            }
        }
        swap(nums[l],nums[j]);
        return j;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int pivotidx=0;
        int l=0;
        int r=nums.size()-1;
        while(true){
            pivotidx=quickSelectAlgo(nums,l,r);
            if(pivotidx==k-1){
                return nums[pivotidx];
            }else if(pivotidx>k-1){
                r=pivotidx-1;
            }else{
                l=pivotidx+1;
            }
        }
        return -1;
    }
};