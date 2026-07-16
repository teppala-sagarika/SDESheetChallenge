// ────────────────────────────────────────────────────────────
// Problem : Kth Largest Element in an Array
// Platform: LeetCode
// URL     : https://leetcode.com/problems/kth-largest-element-in-an-array/submissions/2069384953/
// Language: cpp
// Date    : 7/16/2026, 10:55:47 AM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n log k)
// Space Complexity: O(k)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> min_hp;
        for(int i=0;i<nums.size();i++){
            min_hp.push(nums[i]);
            if(min_hp.size()>k){
                min_hp.pop();
            }
        }
        return min_hp.top();
    }
};