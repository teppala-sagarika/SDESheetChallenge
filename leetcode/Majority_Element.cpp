// ────────────────────────────────────────────────────────────
// Problem : Majority Element
// Platform: LeetCode
// URL     : https://leetcode.com/problems/majority-element/submissions/
// Language: cpp
// Date    : 6/5/2026, 5:47:21 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : Moore's Voting Algorithm
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int el;
        int c=0;
        int n=nums.size();
        //Moore's Voting Algo
        for(int i=0;i<n;i++){
            if(c==0){
                el=nums[i];
                c=1;
            }
            else if(nums[i]==el){
                c++;
            }
            else{
                c--;
            }
        }
        //since element always exists no re verification
        return el;
    }
};