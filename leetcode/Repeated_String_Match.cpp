// ────────────────────────────────────────────────────────────
// Problem : Repeated String Match
// Platform: LeetCode
// URL     : https://leetcode.com/problems/repeated-string-match/
// Language: cpp
// Date    : 6/30/2026, 10:28:12 PM
// ────────────────────────────────────────────────────────────
// Time Complexity : O(B(A+B))
// Space Complexity: O(A+B)
// Notes           : N*A or PREF+N*A+SUF or PREF+N*A
// ────────────────────────────────────────────────────────────

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int B=b.length();
        int A=a.length();
        int n=B/A;
        int c=n;
        string s="";
        while(c--){
            s+=a;
        }
        if(s.find(b)!=std::string::npos){//found
            return n;
        }
        s+=a;
        if(s.find(b)!=std::string::npos){//found
            return n+1;
        }
        s+=a;
        if(s.find(b)!=std::string::npos){//found
            return n+2;
        }
        return -1;
    }
};