// ────────────────────────────────────────────────────────────
// Problem : Best Time to Buy and Sell Stock
// Platform: LeetCode
// URL     : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/2020133387/
// Language: cpp
// Date    : 6/2/2026, 5:17:11 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// Notes           : arrays
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxi=0;
        int n=prices.size();
        for(int i=1;i<n;i++){
            if(prices[i]<mini){
                mini=prices[i];
            }
            else{
                maxi=max(maxi,prices[i]-mini);
            }
        }
        return maxi;
    }
};