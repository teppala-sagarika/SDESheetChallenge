// ────────────────────────────────────────────────────────────
// Problem : Trapping Rain Water
// Platform: LeetCode
// URL     : https://leetcode.com/problems/trapping-rain-water/submissions/2032589447/
// Language: cpp
// Date    : 6/14/2026, 1:26:37 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : arrays
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0,r=n-1;
        int lmx=0,rmx=0;
        int ans=0;
        while(l<r){
            if(height[l]<=height[r]){
                if(lmx>height[l])
                ans+=lmx-height[l];
                else
                lmx=max(lmx,height[l]);
                l++;
            }
            else{
                if(rmx>height[r])
                ans+=rmx-height[r];
                else
                rmx=max(rmx,height[r]);
                r--;
            }
        }
        return ans;
    }
};

//T.C = O(n)
//S.C = O(1)