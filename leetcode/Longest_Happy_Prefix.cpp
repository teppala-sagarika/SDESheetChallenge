// ────────────────────────────────────────────────────────────
// Problem : Longest Happy Prefix
// Platform: LeetCode
// URL     : https://leetcode.com/problems/longest-happy-prefix/
// Language: cpp
// Date    : 7/2/2026, 10:31:37 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// Notes           : Z algo (string pattern matching)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    vector<int> Z_Algo(string s){
        int n=s.size();
        vector<int> z(n,0);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<r){
                //in range (within r)
                z[i]=0+z[i-l];
            if(i+z[i]>r){
                //crosses boundary
                z[i]=r-i;//no. of ele btwn i and r 
            }
            }
            //look beyond boundary
            while(i+z[i]<n && s[z[i]]==s[i+z[i]]){
                //pref == cur+newchar
                z[i]++;
            }
            if(i+z[i]>r){
                //update boundaries
                l=i;
                r=i+z[i];
            }
        }
        return z;
    }
    string longestPrefix(string s) {
        vector<int> z=Z_Algo(s);
        int n=s.size();
        int m=0;
        for(int i=0;i<n;i++){
            if(i + z[i] == n) { // prefix also reaches the end (suffix)
            m = max(m, z[i]);
            }
        }
        return s.substr(0,m);
    }
};