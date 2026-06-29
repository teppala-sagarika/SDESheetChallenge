// ────────────────────────────────────────────────────────────
// Problem : Reverse Words in a String
// Platform: LeetCode
// URL     : https://leetcode.com/problems/reverse-words-in-a-string/submissions/2050174706/
// Language: cpp
// Date    : 6/29/2026, 8:14:36 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(1)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int l=0,r=0;
        int i=0;
        int n=s.length();
        while(i<n){
            while(i<n && s[i]!=' '){
                s[r]=s[i];
                i++;
                r++;
            }
            if(l<r){
                reverse(s.begin()+l,s.begin()+r);
                s[r]=' ';
                r++;
                l=r;
            }
            i++;
        }
        return s.substr(0,r-1);
    }
};