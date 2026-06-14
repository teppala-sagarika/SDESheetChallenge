// ────────────────────────────────────────────────────────────
// Problem : Trapping Rain Water
// Platform: LeetCode
// URL     : https://leetcode.com/problems/trapping-rain-water/submissions/2032563207/
// Language: cpp
// Date    : 6/14/2026, 12:55:20 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// Notes           : arrays
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> left(n),ryt(n);
        int l=0,r=0;
        for(int i=0;i<n;i++){
            l=left[i]=max(l,height[i]);
            r=ryt[n-i-1]=max(r,height[n-1-i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int mini=min(left[i],ryt[i]);
            ans+=mini-height[i];
        }
        return ans;
    }
};