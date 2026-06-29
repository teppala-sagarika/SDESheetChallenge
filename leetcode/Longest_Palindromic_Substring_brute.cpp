class Solution {
public:
    bool isPal(int l,int r,string s){
        if(l>=r){
            return true;
        }
        if(s[l]==s[r]){
            return isPal(l+1,r-1,s);
        }
        return false;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        for(int len = n; len >= 1; len--){
            for(int start = 0; start <= n-len; start++){
                int end = start + len - 1;
                if(isPal(start, end, s)){
                    return s.substr(start, len);
                }
            }
        }
        return "";
    }
};

//TC = O(n^3)
//SC = O(n)
