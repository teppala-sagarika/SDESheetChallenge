class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int len=0;
        for(int i=0;i<n;i++){
            int hash[256]={0};
            for(int j=i;j<n;j++){
                if(hash[s[j]]==1){
                    break;
                }
                len=max(len,j-i+1);
                hash[s[j]]=1;
            }
        }
        return len;
    }
};

//T.C = O(n^2)
//S.C = O(256) = O(1)
