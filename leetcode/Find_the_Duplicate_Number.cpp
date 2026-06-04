// ────────────────────────────────────────────────────────────
// Problem : Find the Duplicate Number
// Platform: LeetCode
// URL     : https://leetcode.com/problems/find-the-duplicate-number/submissions/2022062077/
// Language: cpp
// Date    : 6/4/2026, 1:42:16 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : Floyd’s Cycle Detection Algorithm
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0];
        int fast=nums[0];
        //slow = 1 step , fast = 2 steps
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        fast=nums[0];
        //slow= 1 step and fast = 1 step
        while(slow!=fast){
           slow=nums[slow];
           fast=nums[fast]; 
        }
        return slow;
    }
};
//initially slow = 1 step , fast = 2 steps
//after 1st collision
//slow= 1 step and fast = 1 step
//2nd collision is where u get the duplicate 

//T.C = O(n)
//S.C = O(1)