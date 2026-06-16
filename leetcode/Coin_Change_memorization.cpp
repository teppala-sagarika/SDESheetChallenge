class Solution {
public:
    int solve(int i,vector<int>& coins,int n,int amt, vector<vector<int>>& dp){
        if(amt==0){
            return 0;
        }
        if(i>=n) return 1e9;
        if(dp[i][amt]!=-1){
            return dp[i][amt];
        }
        int notake=solve(i+1,coins,n,amt,dp);
        int take=1e9;
        if(coins[i]<=amt){
            take=1+solve(i,coins,n,amt-coins[i],dp);
        }
        return dp[i][amt]=min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.rbegin(),coins.rend());
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans=solve(0,coins,n,amount,dp);
        return ans==1e9?-1:ans;
    }
};

//T.C = O(n*amount)
//S.C = O(n*amount)
