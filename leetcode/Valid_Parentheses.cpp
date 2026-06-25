// ────────────────────────────────────────────────────────────
// Problem : Valid Parentheses
// Platform: LeetCode
// URL     : https://leetcode.com/problems/valid-parentheses/description/
// Language: cpp
// Date    : 6/25/2026, 11:00:42 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n)
// Space Complexity: O(n)
// Notes           : stack
// ────────────────────────────────────────────────────────────

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char,char> mp = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };
        for(char ch:s){
            if(mp.find(ch)!=mp.end()){
                st.push(ch);
            }
            else{
                if(st.empty()) return false;
                char top=st.top();
                st.pop();
                if(mp[top]!=ch){
                    return false;
                }
            }
        }
        return st.empty();
    }
};