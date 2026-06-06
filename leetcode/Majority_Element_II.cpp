// ────────────────────────────────────────────────────────────
// Problem : Majority Element II
// Platform: LeetCode
// URL     : https://leetcode.com/problems/majority-element-ii/submissions/2023941588/
// Language: cpp
// Date    : 6/6/2026, 12:20:02 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// Notes           : Moore's Voting Algo
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=INT_MIN,el2=INT_MIN;
        int c1=0,c2=0;
        //Moore's Voting Algo
        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=el2){
                c1++;
                el1=nums[i];
            }
            else if(c2==0 && nums[i]!=el1){
                c2++;
                el2=nums[i];
            }
            else if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
            else{
                c1--;
                c2--;
            }
        }
        //check
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                c1++;
            }
            if(nums[i]==el2){
                c2++;
            }
        }
        vector<int> ans;
        if(c1>n/3){
            ans.push_back(el1);
        }
        if(c2>n/3){
            ans.push_back(el2);
        }
        return ans;
    }
};