class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> cur(amount+1,1e9),nxt(amount+1,1e9);
        cur[0]=0;
        nxt[0]=0;
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=amount;j++){
            int notake=nxt[j];
            int take=1e9;
            if(coins[i]<=j){
            take=1+cur[j-coins[i]];
            }
            cur[j]=min(take,notake);
            }
            nxt=cur;
        }
        int ans=cur[amount];
        return ans==1e9?-1:ans;
    }
};

//T.C = O(n*amount)
//S.C = O(amount)
