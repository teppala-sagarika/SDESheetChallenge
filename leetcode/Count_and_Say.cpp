// ────────────────────────────────────────────────────────────
// Problem : Count and Say
// Platform: LeetCode
// URL     : https://leetcode.com/problems/count-and-say/description/
// Language: cpp
// Date    : 7/4/2026, 6:29:01 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(length of final string)
// Space Complexity: O(length of final string)+O(n)
// ────────────────────────────────────────────────────────────

class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string say=countAndSay(n-1);
        int len=say.size();
        int i=0;
        int c=0;
        char ch=say[0];
        string ans="";
        while (i<len){
            if(ch==say[i]){
                c++;
            }else{
                ans+=to_string(c)+ch;
                ch=say[i];
                c=1;
            }
            i++;
        }
        ans+=to_string(c)+ch;
        return ans;
    }
};