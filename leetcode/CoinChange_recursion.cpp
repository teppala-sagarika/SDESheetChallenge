class Solution {
public:
    int solve(int i,vector<int>& coins,int n,int amt){
        if(amt==0){
            return 0;
        }
        if(i>=n) return 1e9;
        int notake=solve(i+1,coins,n,amt);
        int take=1e9;
        if(coins[i]<=amt){
            take=1+solve(i,coins,n,amt-coins[i]);
        }
        return min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.rbegin(),coins.rend());
        int ans=solve(0,coins,n,amount);
        return ans==1e9?-1:ans;
    }
};

//T.C = O(2^(n+amount/min(coin)))
//S.C = O(amount/min(coins))
