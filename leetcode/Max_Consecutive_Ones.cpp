// ────────────────────────────────────────────────────────────
// Problem : Max Consecutive Ones
// Platform: LeetCode
// URL     : https://leetcode.com/problems/max-consecutive-ones/submissions/2032658734/
// Language: cpp
// Date    : 6/14/2026, 2:56:31 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : arrays
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n=nums.size();
        int c=0,mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                c++;
                mx=max(mx,c);
            }else{
                c=0;
            }
        }
        return mx;
    }
};