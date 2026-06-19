class Solution {
public:
    bool solve(int i,int n,string& s, unordered_set<string>& dict){
        if(i==n){
            return true;
        }
        for(int l=1;i+l<=n ;l++){
            string sub=s.substr(i,l);
            if(dict.find(sub)!=dict.end() && solve(i+l,n,s,dict)){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        return solve(0,n,s,dict);
    }
};

//T.C = O(2^n)
//S.C = O(n)
