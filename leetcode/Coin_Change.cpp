// ────────────────────────────────────────────────────────────
// Problem : Coin Change
// Platform: LeetCode
// URL     : https://leetcode.com/problems/coin-change/submissions/2034994119/
// Language: cpp
// Date    : 6/16/2026, 3:25:46 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n*amount)
// Space Complexity: O(n*amount)
// Notes           : tabulation
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1,1e9));
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
            int notake=dp[i+1][j];
            int take=1e9;
            if(coins[i]<=j){
            take=1+dp[i][j-coins[i]];
            }
            dp[i][j]=min(take,notake);
            }
        }
        int ans=dp[0][amount];
        return ans==1e9?-1:ans;
    }
};