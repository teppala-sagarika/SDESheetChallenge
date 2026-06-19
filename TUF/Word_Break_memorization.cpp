class Solution {
public:
    bool solve(int i,int n,string& s, unordered_set<string>& dict,vector<int>& dp){
        if(i==n){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        for(int l=1;i+l<=n ;l++){
            string sub=s.substr(i,l);
            if(dict.find(sub)!=dict.end() && solve(i+l,n,s,dict,dp)){
                return dp[i]=true;
            }
        }
        return dp[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        vector<int> dp(n,-1);
        return solve(0,n,s,dict,dp);
    }
};

//T.C = O(n^3)
//S.C = O(n)
