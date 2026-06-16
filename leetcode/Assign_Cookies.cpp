// ────────────────────────────────────────────────────────────
// Problem : Assign Cookies
// Platform: LeetCode
// URL     : https://leetcode.com/problems/assign-cookies/submissions/2035221735/
// Language: cpp
// Date    : 6/16/2026, 7:15:08 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(n log n + m log m)
// Space Complexity: O(1)
// Notes           : greedy
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int c=0;
        sort(s.begin(),s.end());
        sort(g.begin(),g.end());
        int n=g.size();
        int m=s.size();
        int i=0,j=0;
        while(i<n && j<m){
            if(s[j]>=g[i]){
                c++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return c;
    }
};

//T.C = O(n log n + m log m)
//S.C =O(1)